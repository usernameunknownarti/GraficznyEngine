#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include "Point2D.h"
#include "LineSegment.h"
#include <vector>

/**
 * @class PrimitiveRenderer
 * @brief Klasa odpowiedzialna za renderowanie prymitywnych kształtów geometrycznych na buforze.
 */
class PrimitiveRenderer {
public:
    /**
     * @brief Rysuje pojedynczy punkt w buforze.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param point Obiekt Point2D reprezentujący pozycję punktu.
     * @param color Kolor punktu, reprezentowany jako liczba całkowita.
     */
    void rysujPunkt(std::vector<std::vector<int>>& buffer, const Point2D& point, int color);

    /**
     * @brief Rysuje linię w buforze.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param line Obiekt LineSegment reprezentujący odcinek do narysowania.
     * @param color Kolor linii, reprezentowany jako liczba całkowita.
     */
    void rysujLinia(std::vector<std::vector<int>>& buffer, const LineSegment& line, int color);

    /**
     * @brief Rysuje kwadrat w buforze.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param points Wektor czterech obiektów Point2D reprezentujących wierzchołki kwadratu.
     * @param color Kolor kwadratu, reprezentowany jako liczba całkowita.
     */
    void rysujKwadrat(std::vector<std::vector<int>>& buffer, const std::vector<Point2D>& points, int color);

    /**
     * @brief Rysuje okrąg w buforze.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param center Obiekt Point2D reprezentujący środek okręgu.
     * @param radius Promień okręgu.
     * @param color Kolor okręgu, reprezentowany jako liczba całkowita.
     */
    void rysujKolo(std::vector<std::vector<int>>& buffer, const Point2D& center, int radius, int color);

    /**
     * @brief Wypełnia obszar kolorem metodą flood-fill.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param x Pozycja x punktu początkowego.
     * @param y Pozycja y punktu początkowego.
     * @param fillColor Kolor wypełnienia, reprezentowany jako liczba całkowita.
     * @param backgroundColor Kolor tła, reprezentowany jako liczba całkowita.
     */
    void wypelnijFloodFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int backgroundColor);

    /**
     * @brief Wypełnia obszar kolorem metodą boundary-fill.
     * @param buffer Dwuwymiarowy bufor reprezentujący obszar rysowania.
     * @param x Pozycja x punktu początkowego.
     * @param y Pozycja y punktu początkowego.
     * @param fillColor Kolor wypełnienia, reprezentowany jako liczba całkowita.
     * @param boundaryColor Kolor granicy, reprezentowany jako liczba całkowita.
     */
    void wypelnijBoundaryFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int boundaryColor);
};

#endif // PRIMITIVE_RENDERER_H