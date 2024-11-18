#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <vector>
#include <stack>
#include <cmath>

/**
 * @brief Ustawia piksel o określonym kolorze w buforze ekranu.
 *
 * Funkcja sprawdza, czy współrzędne piksela mieszczą się w granicach ekranu.
 * Jeśli tak, to ustawia piksel o zadanym kolorze na określonej pozycji (x, y).
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param x Współrzędna X piksela do ustawienia.
 * @param y Współrzędna Y piksela do ustawienia.
 * @param color Kolor piksela, reprezentowany jako liczba całkowita.
 */
void setPixel(std::vector<std::vector<int>>& buffer, int x, int y, int color) {
	if (x >= 0 && x < buffer[0].size() && y >= 0 && y < buffer.size()) {
		buffer[y][x] = color; // Ustawia kolor piksela w odpowiedniej pozycji
	}
}

/**
 * @brief Rysuje pojedynczy punkt w buforze ekranu.
 *
 * Funkcja rysuje punkt, ustawiając piksel na określonej pozycji (x, y) w buforze
 * przy użyciu podanego koloru.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param point Punkt, który ma zostać narysowany.
 * @param color Kolor punktu, reprezentowany jako liczba całkowita.
 */
void PrimitiveRenderer::rysujPunkt(std::vector<std::vector<int>>& buffer, const Point2D& point, int color) {
	setPixel(buffer, point.getX(), point.getY(), color); // Wywołanie funkcji setPixel
}

/**
 * @brief Rysuje linię między dwoma punktami za pomocą algorytmu Bresenhama.
 *
 * Algorytm Bresenhama jest wydajnym algorytmem do rysowania prostych linii
 * w grafice komputerowej. Działa szybko, ponieważ używa tylko operacji
 * całkowitoliczbowych.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param line Odcinek linii z dwoma punktami (początkowym i końcowym).
 * @param color Kolor linii, reprezentowany jako liczba całkowita.
 */
void PrimitiveRenderer::rysujLinia(std::vector<std::vector<int>>& buffer, const LineSegment& line, int color) {
	int x1 = line.getStart().getX(); // Współrzędna X punktu początkowego
	int y1 = line.getStart().getY(); // Współrzędna Y punktu początkowego
	int x2 = line.getEnd().getX(); // Współrzędna X punktu końcowego
	int y2 = line.getEnd().getY(); // Współrzędna Y punktu końcowego

	// Obliczenia różnic dla kierunku linii
	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = dx + dy, e2;

	// Pętla rysująca linię
	while (true) {
		setPixel(buffer, x1, y1, color);  // Rysowanie piksela na bieżącej pozycji
		if (x1 == x2 && y1 == y2) break;  // Przerwanie, gdy osiągnięto punkt końcowy
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x1 += sx; } // Przemieszczenie w kierunku osi X
		if (e2 <= dx) { err += dx; y1 += sy; } // Przemieszczenie w kierunku osi Y
	}
}

/**
 * @brief Rysuje kwadrat na podstawie czterech wierzchołków.
 *
 * Kwadrat rysowany jest przez połączenie czterech wierzchołków liniami.
 * Funkcja zakłada, że wierzchołki są podane w odpowiedniej kolejności.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param points Wektor punktów (czterech wierzchołków kwadratu).
 * @param color Kolor kwadratu, reprezentowany jako liczba całkowita.
 */
void PrimitiveRenderer::rysujKwadrat(std::vector<std::vector<int>>& buffer, const std::vector<Point2D>& points, int color) {
	if (points.size() < 4) return; // Jeśli nie ma wystarczającej liczby punktów, nic nie rysuj

	// Rysowanie czterech linii, tworzących kwadrat
	rysujLinia(buffer, LineSegment(points[0], points[1]), color);
	rysujLinia(buffer, LineSegment(points[1], points[2]), color);
	rysujLinia(buffer, LineSegment(points[2], points[3]), color);
	rysujLinia(buffer, LineSegment(points[3], points[0]), color);
}

/**
 * @brief Rysuje okrąg przy użyciu algorytmu Bresenhama dla okręgów.
 *
 * Algorytm Bresenhama dla okręgów wykorzystuje symetrię okręgu, aby obliczyć
 * piksele w ośmiu różnych częściach okręgu (oktantach), co przyspiesza obliczenia.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param center Środek okręgu (punkt).
 * @param radius Promień okręgu.
 * @param color Kolor okręgu, reprezentowany jako liczba całkowita.
 */
void PrimitiveRenderer::rysujKolo(std::vector<std::vector<int>>& buffer, const Point2D& center, int radius, int color) {
	int x = 0;
	int y = radius;
	int d = 3 - 2 * radius; // Parametr decyzyjny algorytmu

	// Pętla rysująca okrąg
	while (y >= x) {
		// Rysowanie punktów na podstawie symetrii okręgu
		setPixel(buffer, center.getX() + x, center.getY() + y, color);
		setPixel(buffer, center.getX() - x, center.getY() + y, color);
		setPixel(buffer, center.getX() + x, center.getY() - y, color);
		setPixel(buffer, center.getX() - x, center.getY() - y, color);
		setPixel(buffer, center.getX() + y, center.getY() + x, color);
		setPixel(buffer, center.getX() - y, center.getY() + x, color);
		setPixel(buffer, center.getX() + y, center.getY() - x, color);
		setPixel(buffer, center.getX() - y, center.getY() - x, color);

		// Dostosowanie parametru decyzyjnego
		x++;
		if (d > 0) {
			y--; // Korekta, gdy przekroczono okrąg
			d += 4 * (x - y) + 10;
		}
		else {
			d += 4 * x + 6; // Aktualizacja parametru, gdy okrąg nie przekroczył
		}
	}
}

/**
 * @brief Wypełnia obszar kolorem metodą flood-fill.
 *
 * Algorytm wypełnia obszar zaczynając od zadanego punktu, zmieniając wszystkie
 * piksele w obszarze na zadany kolor. Zatrzymuje się, gdy natrafi na inny kolor.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param x Współrzędna X punktu początkowego.
 * @param y Współrzędna Y punktu początkowego.
 * @param fillColor Kolor wypełnienia.
 * @param backgroundColor Kolor, który oznacza obszar do wypełnienia.
 */
void PrimitiveRenderer::wypelnijFloodFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int backgroundColor) {
	if (x < 0 || x >= buffer[0].size() || y < 0 || y >= buffer.size()) return;
	if (buffer[y][x] != backgroundColor) return;

	std::stack<Point2D> stack;
	stack.push(Point2D(x, y)); // Dodanie punktu początkowego na stos

	// Pętla wypełniająca obszar
	while (!stack.empty()) {
		Point2D p = stack.top(); // Pobieranie punktu ze stosu
		stack.pop();
		int px = p.getX();
		int py = p.getY();

		if (px >= 0 && px < buffer[0].size() && py >= 0 && py < buffer.size() && buffer[py][px] == backgroundColor) {
			buffer[py][px] = fillColor; // Wypełnianie piksela kolorem

			// Dodanie sąsiednich punktów do wypełnienia
			stack.push(Point2D(px + 1, py));
			stack.push(Point2D(px - 1, py));
			stack.push(Point2D(px, py + 1));
			stack.push(Point2D(px, py - 1));
		}
	}
}

/**
 * @brief Wypełnia obszar kolorem metodą boundary-fill.
 *
 * Algorytm wypełnia obszar kolorami, aż napotka granicę (obrys), który
 * ma inny kolor niż kolor wypełnienia.
 *
 * @param buffer Dwuwymiarowa tablica (wektor wektorów) reprezentująca ekran.
 * @param x Współrzędna X punktu początkowego.
 * @param y Współrzędna Y punktu początkowego.
 * @param fillColor Kolor wypełnienia.
 * @param boundaryColor Kolor granicy, który nie może być nadpisany.
 */
void PrimitiveRenderer::wypelnijBoundaryFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int boundaryColor) {
	if (x < 0 || x >= buffer[0].size() || y < 0 || y >= buffer.size()) return;
	if (buffer[y][x] == fillColor || buffer[y][x] == boundaryColor) return;

	std::stack<Point2D> stack;
	stack.push(Point2D(x, y)); // Dodanie punktu początkowego na stos

	// Pętla wypełniająca obszar
	while (!stack.empty()) {
		Point2D p = stack.top(); // Pobieranie punktu ze stosu
		stack.pop();
		int px = p.getX();
		int py = p.getY();

		if (px >= 0 && px < buffer[0].size() && py >= 0 && py < buffer.size() && buffer[py][px] != boundaryColor && buffer[py][px] != fillColor) {
			buffer[py][px] = fillColor; // Wypełnianie piksela

			// Dodanie sąsiednich punktów do wypełnienia
			stack.push(Point2D(px + 1, py));
			stack.push(Point2D(px - 1, py));
			stack.push(Point2D(px, py + 1));
			stack.push(Point2D(px, py - 1));
		}
	}
}