
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const int BLACK = 0;
const int WHITE = 1;
const int RED = 2;
const int BLUE = 3;
const int GREEN = 4;

int main() {
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Graficzny Engine");

    // 2D Buffer for drawing
    std::vector<std::vector<int>> buffer(windowHeight, std::vector<int>(windowWidth, BLACK));

    // Initialize primitive renderer
    PrimitiveRenderer renderer;

    // Initialize primitives
    Point2D circleCenter(windowWidth / 2, windowHeight / 2);
    int circleRadius = 30;
    LineSegment line(Point2D(100, 100), Point2D(700, 500));

    // Load sprite and texture
    sf::Sprite sprite = TextureManager::loadSprite("Sprite.png");
    TextureManager::spriteSetPosition(sprite, windowWidth / 2 - 8 / 2, windowHeight / 2 - 8 / 2);

    sf::Sprite textureSprite = TextureManager::loadTexture("Image.png");
    TextureManager::setTexturePosition(textureSprite, 300, 400);

    // Check if textures loaded successfully
    if (!sprite.getTexture() || !textureSprite.getTexture()) {
        std::cerr << "Error: Failed to load texture(s)" << std::endl;
        return -1;
    }

    std::cout << "Texture position: " << textureSprite.getPosition().x << ", " << textureSprite.getPosition().y << std::endl;

    // Scale adjustments
    sprite.setScale(20.0f, 20.0f);
    textureSprite.setScale(0.3f, 0.3f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Animate sprite
        TextureManager::animateSprite(sprite, deltaTime);

        // Move circle with arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && circleCenter.x - circleRadius > 0) {
            circleCenter.x -= 5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && circleCenter.x + circleRadius < windowWidth) {
            circleCenter.x += 5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && circleCenter.y - circleRadius > 0) {
            circleCenter.y -= 5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circleCenter.y + circleRadius < windowHeight) {
            circleCenter.y += 5;
        }

        // Clear window and buffer for each frame
        window.clear();
        for (auto& row : buffer) {
            std::fill(row.begin(), row.end(), BLACK);
        }

        // Draw circle and line in the buffer
        renderer.rysujKolo(buffer, circleCenter, circleRadius, WHITE);
        renderer.wypelnijFloodFill(buffer, circleCenter.getX(), circleCenter.getY(), BLUE, BLACK);
        renderer.rysujLinia(buffer, line, RED);

        // Create an SFML image from the buffer
        sf::Image image;
        image.create(windowWidth, windowHeight, sf::Color::Black);
        for (int y = 0; y < windowHeight; ++y) {
            for (int x = 0; x < windowWidth; ++x) {
                if (buffer[y][x] == WHITE) {
                    image.setPixel(x, y, sf::Color::White);
                }
                else if (buffer[y][x] == BLUE) {
                    image.setPixel(x, y, sf::Color::Blue);
                }
                else if (buffer[y][x] == RED) {
                    image.setPixel(x, y, sf::Color::Red);
                }
            }
        }

        //// 2D Buffer for drawing
        //std::vector<std::vector<int>> buffer(windowHeight, std::vector<int>(windowWidth, BLACK));

        //// Initialize primitive renderer
        //PrimitiveRenderer renderer;

        //// Parametry kwadratu
        //float centerX = windowWidth / 2;
        //float centerY = windowHeight / 2;
        //float size = 100.0f; // Początkowy rozmiar kwadratu
        //float scaleX = 1.5f; // Współczynnik skalowania w osi X
        //float scaleY = 1.5f; // Współczynnik skalowania w osi Y

        //// Tworzymy kwadrat, który jest powiększony i obrócony
        //std::vector<Point2D> squarePoints = createTransformedSquare(centerX, centerY, size, scaleX, scaleY);

        //// Rysowanie kwadratu w buforze
        //renderer.rysujKwadrat(buffer, squarePoints, WHITE);

        // Renderowanie wyników na ekranie
        /*sf::Image image;
        image.create(windowWidth, windowHeight, sf::Color::Black);
        for (int y = 0; y < windowHeight; ++y) {
            for (int x = 0; x < windowWidth; ++x) {
                if (buffer[y][x] == WHITE) {
                    image.setPixel(x, y, sf::Color::White);
                }
            }
        }*/

        // Load image to texture and create sprite for drawing buffer
        sf::Texture texture;
        texture.loadFromImage(image);
        sf::Sprite bufferSprite(texture);
        window.draw(bufferSprite);

        // Draw additional sprites
        window.draw(textureSprite);
        window.draw(sprite);

        // Display frame
        window.display();
    }

    return 0;
}
