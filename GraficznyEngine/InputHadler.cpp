#include <SFML/Window.hpp>
#include <queue>

class InputHandler {
public:
    enum class EventType {
        KeyPress,
        KeyRelease,
        MouseButtonPress,
        MouseButtonRelease,
        None
    };

    struct Event {
        EventType type;
        sf::Keyboard::Key key;
        sf::Mouse::Button button;

        Event(EventType t = EventType::None, sf::Keyboard::Key k = sf::Keyboard::Unknown, sf::Mouse::Button b = sf::Mouse::Button::ButtonCount)
            : type(t), key(k), button(b) {}
    };

    bool IsKeyPressed(sf::Keyboard::Key key) const;
    Event ReadEvent();
    bool IsEventQueueEmpty() const;

    void OnKeyPressed(sf::Keyboard::Key key);
    void OnKeyReleased(sf::Keyboard::Key key);
    void OnMouseButtonPressed(sf::Mouse::Button button);
    void OnMouseButtonReleased(sf::Mouse::Button button);

    void Clear();

private:
    std::queue<Event> eventQueue;
    bool keyStates[sf::Keyboard::KeyCount] = { false };

    static constexpr size_t maxBufferSize = 32;

    template <typename T>
    void TrimBuffer(std::queue<T>& buffer);
};

// Implementacja metod
bool InputHandler::IsKeyPressed(sf::Keyboard::Key key) const {
    return keyStates[key];
}

InputHandler::Event InputHandler::ReadEvent() {
    if (!eventQueue.empty()) {
        Event e = eventQueue.front();
        eventQueue.pop();
        return e;
    }
    return Event();
}

bool InputHandler::IsEventQueueEmpty() const {
    return eventQueue.empty();
}

void InputHandler::OnKeyPressed(sf::Keyboard::Key key) {
    keyStates[key] = true;
    eventQueue.push(Event(EventType::KeyPress, key));
    TrimBuffer(eventQueue);
}

void InputHandler::OnKeyReleased(sf::Keyboard::Key key) {
    keyStates[key] = false;
    eventQueue.push(Event(EventType::KeyRelease, key));
    TrimBuffer(eventQueue);
}

void InputHandler::OnMouseButtonPressed(sf::Mouse::Button button) {
    eventQueue.push(Event(EventType::MouseButtonPress, sf::Keyboard::Unknown, button));
    TrimBuffer(eventQueue);
}

void InputHandler::OnMouseButtonReleased(sf::Mouse::Button button) {
    eventQueue.push(Event(EventType::MouseButtonRelease, sf::Keyboard::Unknown, button));
    TrimBuffer(eventQueue);
}

void InputHandler::Clear() {
    while (!eventQueue.empty()) {
        eventQueue.pop();
    }
    std::fill(std::begin(keyStates), std::end(keyStates), false);
}

template <typename T>
void InputHandler::TrimBuffer(std::queue<T>& buffer) {
    while (buffer.size() > maxBufferSize) {
        buffer.pop();
    }
}
