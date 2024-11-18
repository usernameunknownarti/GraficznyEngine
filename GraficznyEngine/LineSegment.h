
#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"

/**
 * @class LineSegment
 * @brief Klasa reprezentująca odcinek linii w przestrzeni 2D.
 *
 * Odcinek linii jest zdefiniowany przez dwa punkty: punkt początkowy i punkt końcowy.
 * Ta klasa oferuje funkcje umożliwiające przesuwanie, obracanie i skalowanie odcinka linii.
 */
class LineSegment {
public:
    /**
     * @brief Konstruktor klasy LineSegment.
     *
     * Tworzy nowy odcinek linii z dwóch punktów: początkowego i końcowego.
     *
     * @param start Punkt początkowy odcinka linii.
     * @param end Punkt końcowy odcinka linii.
     */
    LineSegment(const Point2D& start, const Point2D& end) : start(start), koniec(end) {}

    /**
     * @brief Pobiera punkt początkowy odcinka linii.
     *
     * Ta funkcja zwraca punkt początkowy, który jest pierwszym punktem odcinka linii.
     *
     * @return Stała referencja do punktu początkowego odcinka.
     */
    const Point2D& getStart() const { return start; }

    /**
     * @brief Pobiera punkt końcowy odcinka linii.
     *
     * Ta funkcja zwraca punkt końcowy, który jest drugim punktem odcinka linii.
     *
     * @return Stała referencja do punktu końcowego odcinka.
     */
    const Point2D& getEnd() const { return koniec; }

    /**
     * @brief Przesuwa odcinek linii o określoną odległość.
     *
     * Przesuwa punkt początkowy i końcowy odcinka o wartości translacji (tx, ty).
     *
     * @param tx Wartość translacji w kierunku osi X.
     * @param ty Wartość translacji w kierunku osi Y.
     */
    void translacja(float tx, float ty) {
        start.translacja(tx, ty);  // Przesuwamy punkt początkowy
        koniec.translacja(tx, ty);  // Przesuwamy punkt końcowy
    }

    /**
     * @brief Obraca odcinek linii wokół punktu (0,0).
     *
     * Obraca odcinek linii o zadany kąt alpha wokół początku układu współrzędnych.
     *
     * @param alpha Kąt obrotu w stopniach (np. 90 dla obrotu o 90 stopni).
     */
    void rotacja(float alpha) {
        start.rotacja(alpha);  // Obracamy punkt początkowy
        koniec.rotacja(alpha);  // Obracamy punkt końcowy
    }

    /**
     * @brief Obraca odcinek linii wokół dowolnego punktu.
     *
     * Obraca odcinek linii o zadany kąt alpha wokół punktu (x0, y0).
     *
     * @param x0 Współrzędna X punktu, wokół którego odbywa się obrót.
     * @param y0 Współrzędna Y punktu, wokół którego odbywa się obrót.
     * @param alpha Kąt obrotu w stopniach (np. 90 dla obrotu o 90 stopni).
     */
    void rotacja(float x0, float y0, float alpha) {
        start.rotacja(x0, y0, alpha);  // Obracamy punkt początkowy wokół (x0, y0)
        koniec.rotacja(x0, y0, alpha);  // Obracamy punkt końcowy wokół (x0, y0)
    }

    /**
     * @brief Skalowanie odcinka linii względem punktu (0,0).
     *
     * Skalowanie oznacza zmianę wielkości odcinka w kierunkach X i Y.
     * Skalowanie jest proporcjonalne do współczynników kx i ky.
     *
     * @param kx Współczynnik skalowania w kierunku osi X (np. 2 oznacza dwukrotne powiększenie).
     * @param ky Współczynnik skalowania w kierunku osi Y (np. 2 oznacza dwukrotne powiększenie).
     */
    void skalowanie(float kx, float ky) {
        start.skalowanie(kx, ky);  // Skalujemy punkt początkowy
        koniec.skalowanie(kx, ky);  // Skalujemy punkt końcowy
    }

    /**
     * @brief Skalowanie odcinka linii względem dowolnego punktu.
     *
     * Skalowanie oznacza zmianę wielkości odcinka w kierunkach X i Y.
     * Skalowanie jest proporcjonalne do współczynników kx i ky i odbywa się wokół punktu (x0, y0).
     *
     * @param x0 Współrzędna X punktu skalowania (punkt centralny).
     * @param y0 Współrzędna Y punktu skalowania (punkt centralny).
     * @param kx Współczynnik skalowania w kierunku osi X.
     * @param ky Współczynnik skalowania w kierunku osi Y.
     */
    void skalowanie(float x0, float y0, float kx, float ky) {
        start.skalowanie(x0, y0, kx, ky);  // Skalujemy punkt początkowy względem (x0, y0)
        koniec.skalowanie(x0, y0, kx, ky);  // Skalujemy punkt końcowy względem (x0, y0)
    }

private:
    Point2D start; ///< Punkt początkowy odcinka linii.
    Point2D koniec; ///< Punkt końcowy odcinka linii.
};

#endif // LINESEGMENT_H