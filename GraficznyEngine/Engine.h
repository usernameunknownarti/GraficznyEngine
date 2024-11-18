#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class Engine
 * @brief Klasa reprezentująca silnik gry, który zarządza główną pętlą, oknem i zdarzeniami.
 */
class Engine {
public:
    /**
     * @brief Konstruktor klasy Engine.
     * @param title Tytuł okna aplikacji.
     * @param width Szerokość okna (jeśli nie w trybie pełnoekranowym).
     * @param height Wysokość okna (jeśli nie w trybie pełnoekranowym).
     * @param fullscreen Określa, czy aplikacja działa w trybie pełnoekranowym.
     */
    Engine(const std::string& title, int width, int height, bool fullscreen);

    /**
     * @brief Destruktor klasy Engine. Zamyka okno aplikacji.
     */
    ~Engine();

    /**
     * @brief Uruchamia główną pętlę silnika gry.
     */
    void run();

    /**
     * @brief Sprawdza, czy silnik nadal działa.
     * @return `true`, jeśli silnik jest uruchomiony, `false` w przeciwnym razie.
     */
    bool isRunning() const { return running; }

    /**
     * @brief Zwraca referencję do obiektu okna SFML.
     * @return Referencja do `sf::RenderWindow`.
     */
    sf::RenderWindow& getWindow() { return okno; }

    /**
     * @brief Czyści ekran określonym kolorem.
     * @param color Kolor używany do czyszczenia ekranu.
     */
    void czysc(const sf::Color& color);

    /**
     * @brief Wyświetla zawartość okna.
     */
    void display();

    /**
     * @brief Obsługuje zdarzenia SFML.
     */
    void eventy();

private:
    /**
     * @brief Obsługuje komunikaty o błędach, zapisując je w pliku logu.
     * @param message Wiadomość błędu do zapisania.
     */
    void errory(const std::string& message);

    sf::RenderWindow okno; ///< Obiekt okna SFML.
    bool running; ///< Flaga określająca, czy silnik jest uruchomiony.
};

#endif // ENGINE_H
