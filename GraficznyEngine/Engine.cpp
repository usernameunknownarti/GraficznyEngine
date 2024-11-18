#include "Engine.h"
#include <iostream>
#include <fstream>

/**
 * @brief Konstruktor klasy Engine.
 * @param title Tytuł okna aplikacji.
 * @param width Szerokość okna (jeśli nie w trybie pełnoekranowym).
 * @param height Wysokość okna (jeśli nie w trybie pełnoekranowym).
 * @param fullscreen Określa, czy aplikacja działa w trybie pełnoekranowym.
 */
Engine::Engine(const std::string& title, int width, int height, bool fullscreen) {
    okno.create(fullscreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode(width, height), title, fullscreen ? sf::Style::Fullscreen : sf::Style::Close);
    running = true;
}

/**
 * @brief Destruktor klasy Engine. Zamyka okno aplikacji.
 */
Engine::~Engine() {
    okno.close();
}

/**
 * @brief Główna pętla aplikacji, która steruje działaniem silnika.
 */
void Engine::run() {
    while (running) {
        eventy(); ///< Obsługuje zdarzenia (np. klawiaturę, mysz, zamknięcie okna).
        czysc(sf::Color::Black); ///< Czyści ekran wybranym kolorem.

        // Tutaj można dodać logikę renderowania i aktualizacji gry.

        display(); ///< Wyświetla zawartość na ekranie.
    }
}

/**
 * @brief Czyści ekran określonym kolorem.
 * @param color Kolor używany do czyszczenia ekranu.
 */
void Engine::czysc(const sf::Color& color) {
    okno.clear(color);
}

/**
 * @brief Wyświetla zawartość okna.
 */
void Engine::display() {
    okno.display();
}

/**
 * @brief Obsługuje zdarzenia SFML, takie jak zamknięcie okna, klawiatura i mysz.
 */
void Engine::eventy() {
    sf::Event event;
    while (okno.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            running = false; ///< Zamyka aplikację, gdy okno zostanie zamknięte.
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                running = false; ///< Zamyka aplikację po wciśnięciu klawisza Escape.
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "mysz kliknieto wspolrzedne: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")\n";
                ///< Wypisuje współrzędne kliknięcia myszą w konsoli.
            }
        }
    }
}

/**
 * @brief Obsługuje komunikaty o błędach, wypisując je do konsoli i zapisując w pliku logu.
 * @param message Wiadomość błędu do zapisania.
 */
void Engine::errory(const std::string& message) {
    std::cerr << message << std::endl; ///< Wypisuje błąd na standardowe wyjście błędów.
    std::ofstream plikLogu("log.txt", std::ios::app); ///< Otwiera plik logu w trybie dopisywania.
    if (plikLogu.is_open()) {
        plikLogu << message << std::endl; ///< Zapisuje wiadomość do pliku.
        plikLogu.close();
    }
}
