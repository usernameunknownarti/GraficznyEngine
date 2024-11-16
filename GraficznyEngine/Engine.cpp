#include "Engine.h"
#include <iostream>
#include <fstream>

Engine::Engine(const std::string& title, int width, int height, bool fullscreen) {
	okno.create(fullscreen ? sf::VideoMode::getFullscreenModes()[0] : sf::VideoMode(width, height), title, fullscreen ? sf::Style::Fullscreen : sf::Style::Close);
	running = true;
}

Engine::~Engine() {
	okno.close();
}

void Engine::run() {
	while (running) {
		eventy();
		czysc(sf::Color::Black);

		

		display();
	}
}

void Engine::czysc(const sf::Color& color) {
	okno.clear(color);
}

void Engine::display() {
	okno.display();
}

void Engine::eventy() {
	sf::Event event;
	while (okno.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			running = false;
		}

		
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				running = false; 
			}
		}

		
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				std::cout << "mysz kliknieto wspolrzedne: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")\n";
				
			}
		}
	}
}

void Engine::errory(const std::string& message) {
	std::cerr << message << std::endl;
	std::ofstream plikLogu("log.txt", std::ios::app);
	if (plikLogu.is_open()) {
		plikLogu << message << std::endl;
		plikLogu.close();
	}
}
