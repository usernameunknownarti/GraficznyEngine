#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

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

        Event(EventType t = EventType::None, sf::Keyboard::Key k = sf::Keyboard::Unknown, sf::Mouse::Button b = sf::Mouse::Button::ButtonCount);
    };


    InputHandler() = default;
    ~InputHandler() = default;


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

#endif //INPUTHANDLER_H