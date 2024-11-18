//#include "TextureManager.h"
//#include <iostream>
//#include <fstream>
//
//sf::Texture TextureManager::spriteTexture;
//sf::Texture TextureManager::imageTexture;
//float TextureManager::timeAcc = 0.0f;
//int TextureManager::currentFrame = 0;
//int frameWidth = 8;
//int frameHeight = 8;
//int frameCount = 4;
//
//sf::Sprite TextureManager::loadSprite(const std::string& filename) {
//    if (!spriteTexture.loadFromFile(filename)) {
//        std::cerr << "Error: Nie mozna pobrac tekstury" << filename << std::endl;
//        return sf::Sprite();
//    }
//
//    sf::Sprite sprite;
//    sprite.setTexture(spriteTexture);
//    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
//
//    return sprite;
//}
//
//void TextureManager::spriteSetPosition(sf::Sprite& sprite, int x, int y) {
//    sprite.setPosition(x, y);
//}
//
//void TextureManager::animateSprite(sf::Sprite& sprite, float delta) {
//    // Okreslenie czasu miedzy klatkami
//    float frameTime = 0.22f;
//    timeAcc += delta;
//
//    if (timeAcc >= frameTime) {
//        timeAcc -= frameTime;
//        currentFrame = (currentFrame + 1) % frameCount;
//    }
//
//    int left = currentFrame * frameWidth;
//
//    if (spriteTexture.getSize().x > 0) {
//        sprite.setTextureRect(sf::IntRect(left, 0, frameWidth, frameHeight));
//    }
//}
//
//sf::Sprite TextureManager::loadTexture(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.good()) {
//        std::cerr << "Error: Plik nie istnieje lub jest nieosiagalny: " << filename << std::endl;
//    }
//
//    sf::Image Image;
//    if (!Image.loadFromFile(filename)) {
//        std::cerr << "Error: Nie mozna pobrac tekstury" << filename <<std::endl;
//        return sf::Sprite();
//    }
//
//    if (!imageTexture.loadFromImage(Image)) {
//        std::cerr << "Error: Nie udalo sie przekonwertowac obrazu do tekstury" << std::endl;
//        return sf::Sprite();
//    }
//
//    sf::Sprite textureSprite;
//    textureSprite.setTexture(imageTexture);
//
//    if (textureSprite.getTexture() == nullptr) {
//        std::cerr << "Error: Nie udalo sie przekonwertowac tekstury do sprite'a" << std::endl;
//        return sf::Sprite();
//    }
//
//    textureSprite.setColor(sf::Color::White);
//    return textureSprite;
//}
//
//void TextureManager::setTexturePosition(sf::Sprite& textureSprite, int x, int y) {
//    textureSprite.setPosition(x, y);
//    std::cout << "Pozycja tekstury:" << textureSprite.getPosition().x << "\t" << textureSprite.getPosition().y << std::endl;
//}
//
//


#include "TextureManager.h"
#include <iostream>
#include <fstream>


sf::Texture TextureManager::spriteTexture;
sf::Texture TextureManager::imageTexture;
float TextureManager::timeAcc = 0.0f;
int TextureManager::currentFrame = 0;
int frameWidth = 8;
int frameHeight = 8;
int frameCount = 4;


sf::Sprite TextureManager::loadSprite(const std::string& filename) {

    if (!spriteTexture.loadFromFile(filename)) {
        std::cerr << "Error: Nie mozna pobrac tekstury " << filename << std::endl;
        return sf::Sprite();
    }

    sf::Sprite sprite;
    sprite.setTexture(spriteTexture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));

    return sprite;
}

void TextureManager::spriteSetPosition(sf::Sprite& sprite, int x, int y) {
    sprite.setPosition(x, y);
}


void TextureManager::animateSprite(sf::Sprite& sprite, float delta) {

    float frameTime = 0.22f;
    timeAcc += delta;


    if (timeAcc >= frameTime) {
        timeAcc -= frameTime;
        currentFrame = (currentFrame + 1) % frameCount;
    }

    int left = currentFrame * frameWidth;


    if (spriteTexture.getSize().x > 0) {
        sprite.setTextureRect(sf::IntRect(left, 0, frameWidth, frameHeight));  // Ustawienie nowego prostokata dla tekstury
    }
}

sf::Sprite TextureManager::loadTexture(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << "Error: Plik nie istnieje lub jest nieosiagalny: " << filename << std::endl;
    }

    sf::Image Image;
    if (!Image.loadFromFile(filename)) {
        std::cerr << "Error: Nie mozna pobrac tekstury " << filename << std::endl;
        return sf::Sprite();
    }

    if (!imageTexture.loadFromImage(Image)) {
        std::cerr << "Error: Nie udalo sie przekonwertowac obrazu do tekstury" << std::endl;
        return sf::Sprite();
    }

    sf::Sprite textureSprite;
    textureSprite.setTexture(imageTexture);

    if (textureSprite.getTexture() == nullptr) {
        std::cerr << "Error: Nie udalo sie przekonwertowac tekstury do sprite'a" << std::endl;
        return sf::Sprite();
    }

    textureSprite.setColor(sf::Color::White);

    return textureSprite;
}

void TextureManager::setTexturePosition(sf::Sprite& textureSprite, int x, int y) {
    textureSprite.setPosition(x, y);
    std::cout << "Pozycja tekstury:" << textureSprite.getPosition().x << "/t" << textureSprite.getPosition().y << std::endl;
}

sf::Texture TextureManager::Bitmap(const std::string& filename) {
    sf::Image image;
    if (!image.loadFromFile(filename)) {
        std::cerr << "Blad mamy, ale obrazu nie." << std::endl;

    }

    // Pobieranie rozmiarów obrazu
    sf::Vector2u size = image.getSize();

    // Iterowanie po wszystkich pikselach obrazu
    for (unsigned int x = 0; x < size.x; ++x) {
        for (unsigned int y = 0; y < size.y; ++y) {
            // Pobieranie koloru piksela
            sf::Color color = image.getPixel(x, y);

            // Przykład operacji na kolorze: NEGATYW
            //sf::Color newColor = sf::Color(255 - color.r, 255 - color.g, 255 - color.b);

            // Możesz dodać inne operacje na kolorach, np. zmiana jasności:
            // sf::Color newColor = sf::Color(color.r * 0.8f, color.g * 0.8f, color.b * 0.8f);

            // Ustawianie zmienionego koloru na odpowiednim pikselu
           // image.setPixel(x, y, newColor);
        }
    }

    // Tworzenie tekstury z przetworzonego obrazu
    sf::Texture texture;
    texture.loadFromImage(image);

    // Tworzenie okna do wyświetlania obrazu
   // sf::RenderWindow window(sf::VideoMode(800, 600), "Przetworzony Obraz");

    return texture;
}