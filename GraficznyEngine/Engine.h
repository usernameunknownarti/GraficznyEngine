#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

class Engine {
public:
	Engine(const std::string& title, int width, int height, bool fullscreen);
	~Engine();

	void run();
	bool isRunning() const { return running; }
	sf::RenderWindow& getWindow() { return okno; }
	void czysc(const sf::Color& color);
	void display();
	void eventy();
private:
	
	void errory(const std::string& message);

	sf::RenderWindow okno;
	bool running;
};

#endif // ENGINE_H
