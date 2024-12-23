//#ifndef TEXTUREMANAGER_H
//#define TEXTUREMANAGER_H
//
//#include <SFML/Graphics.hpp>
//#include <string>
//#include <iostream>
//
//class TextureManager {
//public:
//    static sf::Texture spriteTexture;
//    static sf::Texture imageTexture;
//    static float timeAcc;
//    static int currentFrame;
//
//    static sf::Sprite loadSprite(const std::string& filename);
//
//    static void spriteSetPosition(sf::Sprite& sprite, int x, int y);
//
//    static void animateSprite(sf::Sprite& sprite, float delta);
//
//    static sf::Sprite loadTexture(const std::string& filename);
//
//    static void setTexturePosition(sf::Sprite& textureSprite, int x, int y);
//
//
//private:
//   
//
//#endif
//};


#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class TextureManager {
public:

    static sf::Texture spriteTexture;
    static sf::Texture imageTexture;
    static float timeAcc;
    static int currentFrame;
    // Funkcja laduje sprite'a z pliku
    static sf::Sprite loadSprite(const std::string& filename);

    // Funkcja ustawia pozycje sprite'a w oknie
    static void spriteSetPosition(sf::Sprite& sprite, int x, int y);

    // Funkcja do animowania sprite'a - zmienia klatki animacji
    static void animateSprite(sf::Sprite& sprite, float delta);

    // Funkcja laduje teksture z pliku (np. dla tła)
    static sf::Sprite loadTexture(const std::string& filename);

    // Funkcja ustawia pozycje tekstury w oknie
    static void setTexturePosition(sf::Sprite& textureSprite, int x, int y);

    static sf::Texture Bitmap(const std::string& filename);


};

#endif  // Koniec definicji klasy
