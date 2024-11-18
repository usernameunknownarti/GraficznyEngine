#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>

/// @brief Wartość stałej Pi.
#define M_PI 3.14159265358979323846 

/**
 * @class Point2D
 * @brief Klasa reprezentująca punkt w 2D z podstawowymi operacjami geometrycznymi.
 */
class Point2D {
public:
    /**
     * @brief Konstruktor tworzący punkt 2D.
     * @param x Współrzędna X punktu (domyślnie 0).
     * @param y Współrzędna Y punktu (domyślnie 0).
     */
    Point2D(float x = 0, float y = 0) : x(x), y(y) {}

    /**
     * @brief Pobiera współrzędną X punktu.
     * @return Wartość współrzędnej X.
     */
    float getX() const { return x; }

    /**
     * @brief Pobiera współrzędną Y punktu.
     * @return Wartość współrzędnej Y.
     */
    float getY() const { return y; }

    /**
     * @brief Przesuwa punkt o podane wartości.
     * @param tx Przesunięcie w osi X.
     * @param ty Przesunięcie w osi Y.
     */
    void translacja(float tx, float ty) {
        x += tx;
        y += ty;
    }

    /**
     * @brief Obraca punkt wokół początku układu współrzędnych.
     * @param alpha Kąt obrotu w stopniach.
     */
    void rotacja(float alpha) {
        float rad = alpha * M_PI / 180.0; ///< Konwersja kąta na radiany.
        float newX = x * cos(rad) - y * sin(rad);
        float newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    /**
     * @brief Obraca punkt wokół zadanego środka.
     * @param x0 Współrzędna X środka obrotu.
     * @param y0 Współrzędna Y środka obrotu.
     * @param alpha Kąt obrotu w stopniach.
     */
    void rotacja(float x0, float y0, float alpha) {
        translacja(-x0, -y0); ///< Przesunięcie środka obrotu do początku układu współrzędnych.
        rotacja(alpha); ///< Obrót wokół początku układu współrzędnych.
        translacja(x0, y0); ///< Powrót do oryginalnego układu współrzędnych.
    }

    /**
     * @brief Skaluje punkt względem osi.
     * @param kx Współczynnik skalowania w osi X.
     * @param ky Współczynnik skalowania w osi Y.
     */
    void skalowanie(float kx, float ky) {
        x *= kx;
        y *= ky;
    }

    /**
     * @brief Skaluje punkt względem zadanego środka.
     * @param x0 Współrzędna X środka skalowania.
     * @param y0 Współrzędna Y środka skalowania.
     * @param kx Współczynnik skalowania w osi X.
     * @param ky Współczynnik skalowania w osi Y.
     */
    void skalowanie(float x0, float y0, float kx, float ky) {
        translacja(-x0, -y0); ///< Przesunięcie środka skalowania do początku układu współrzędnych.
        skalowanie(kx, ky); ///< Skalowanie względem początku układu współrzędnych.
        translacja(x0, y0); ///< Powrót do oryginalnego układu współrzędnych.
    }

public:
    float x, y; ///< Współrzędne punktu.
};

#endif // POINT2D_H
