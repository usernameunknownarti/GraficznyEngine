#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Point2D {
public:
	Point2D(float x = 0, float y = 0) : x(x), y(y) {}

	float getX() const { return x; }
	float getY() const { return y; }

	void setX(float newX) { x = newX; }
	void setY(float newY) { y = newY; }

	void draw(sf::RenderWindow& window) const {
		sf::Vertex point(sf::Vector2f(x, y), sf::Color::White);
		window.draw(&point, 1, sf::Points);
	}

private:
	float x, y;
};

class LineSegment {
public:
	LineSegment(const Point2D& p1, const Point2D& p2) : p1(p1), p2(p2) {}

	Point2D getP1() const { return p1; }
	Point2D getP2() const { return p2; }

	void setP1(const Point2D& newP1) { p1 = newP1; }
	void setP2(const Point2D& newP2) { p2 = newP2; }

	void draw(sf::RenderWindow& window, bool incremental = false) const {
		if (incremental) {
			drawIncrementalLine(window, p1, p2);
		}
		else {
			sf::Vertex line[] = {
				sf::Vertex(sf::Vector2f(p1.getX(), p1.getY())),
				sf::Vertex(sf::Vector2f(p2.getX(), p2.getY()))
			};
			window.draw(line, 2, sf::Lines);
		}
	}

private:
	Point2D p1, p2;

	void drawIncrementalLine(sf::RenderWindow& window, const Point2D& start, const Point2D& end) const {
		// Implementacja algorytmu przyrostowego rysowania linii
		int x1 = static_cast<int>(start.getX());
		int y1 = static_cast<int>(start.getY());
		int x2 = static_cast<int>(end.getX());
		int y2 = static_cast<int>(end.getY());

		int dx = x2 - x1;
		int dy = y2 - y1;
		int steps = std::max(abs(dx), abs(dy));

		float xIncrement = dx / static_cast<float>(steps);
		float yIncrement = dy / static_cast<float>(steps);

		float x = x1;
		float y = y1;
		for (int i = 0; i <= steps; ++i) {
			sf::Vertex point(sf::Vector2f(x, y), sf::Color::White);
			window.draw(&point, 1, sf::Points);
			x += xIncrement;
			y += yIncrement;
		}
	}
};

class PrimitiveRenderer {
public:
	void drawPoint(sf::RenderWindow& window, const Point2D& point) {
		point.draw(window);
	}

	void drawLineSegment(sf::RenderWindow& window, const LineSegment& line, bool incremental = false) {
		line.draw(window, incremental);
	}

	void drawPolyline(sf::RenderWindow& window, const std::vector<LineSegment>& segments, bool closed = false) {
		for (const auto& segment : segments) {
			drawLineSegment(window, segment);
		}
		if (closed && !segments.empty()) {
			drawLineSegment(window, LineSegment(segments.back().getP2(), segments.front().getP1()));
		}
	}
};

#endif // PRIMITIVE_RENDERER_H