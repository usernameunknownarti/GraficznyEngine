#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <vector>
#include <stack>
#include <cmath>


void setPixel(std::vector<std::vector<int>>& buffer, int x, int y, int color) {
	if (x >= 0 && x < buffer[0].size() && y >= 0 && y < buffer.size()) {
		buffer[y][x] = color;
	}
}


void PrimitiveRenderer::rysujPunkt(std::vector<std::vector<int>>& buffer, const Point2D& point, int color) {
	setPixel(buffer, point.getX(), point.getY(), color);
}


void PrimitiveRenderer::rysujLinia(std::vector<std::vector<int>>& buffer, const LineSegment& line, int color) {
	int x1 = line.getStart().getX();
	int y1 = line.getStart().getY();
	int x2 = line.getEnd().getX();
	int y2 = line.getEnd().getY();

	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = dx + dy, e2; 

	while (true) {
		setPixel(buffer, x1, y1, color);
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x1 += sx; }
		if (e2 <= dx) { err += dx; y1 += sy; }
	}
}

void PrimitiveRenderer::rysujKwadrat(std::vector<std::vector<int>>& buffer, const std::vector<Point2D>& points, int color) {
	if (points.size() < 4) return;

	rysujLinia(buffer, LineSegment(points[0], points[1]), color);
	rysujLinia(buffer, LineSegment(points[1], points[2]), color);
	rysujLinia(buffer, LineSegment(points[2], points[3]), color);
	rysujLinia(buffer, LineSegment(points[3], points[0]), color);
}


void PrimitiveRenderer::rysujKolo(std::vector<std::vector<int>>& buffer, const Point2D& center, int radius, int color) {
	int x = 0;
	int y = radius;
	int d = 3 - 2 * radius;

	while (y >= x) {
		setPixel(buffer, center.getX() + x, center.getY() + y, color);
		setPixel(buffer, center.getX() - x, center.getY() + y, color);
		setPixel(buffer, center.getX() + x, center.getY() - y, color);
		setPixel(buffer, center.getX() - x, center.getY() - y, color);
		setPixel(buffer, center.getX() + y, center.getY() + x, color);
		setPixel(buffer, center.getX() - y, center.getY() + x, color);
		setPixel(buffer, center.getX() + y, center.getY() - x, color);
		setPixel(buffer, center.getX() - y, center.getY() - x, color);

		x++;
		if (d > 0) {
			y--;
			d += 4 * (x - y) + 10;
		}
		else {
			d += 4 * x + 6;
		}
	}
}

void PrimitiveRenderer::wypelnijFloodFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int backgroundColor) {
	if (x < 0 || x >= buffer[0].size() || y < 0 || y >= buffer.size()) return;
	if (buffer[y][x] != backgroundColor) return;

	std::stack<Point2D> stack;
	stack.push(Point2D(x, y));

	while (!stack.empty()) {
		Point2D p = stack.top();
		stack.pop();
		int px = p.getX();
		int py = p.getY();

		if (px >= 0 && px < buffer[0].size() && py >= 0 && py < buffer.size() && buffer[py][px] == backgroundColor) {
			buffer[py][px] = fillColor;

			stack.push(Point2D(px + 1, py));
			stack.push(Point2D(px - 1, py));
			stack.push(Point2D(px, py + 1));
			stack.push(Point2D(px, py - 1));
		}
	}
}


void PrimitiveRenderer::wypelnijBoundaryFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int boundaryColor) {
	if (x < 0 || x >= buffer[0].size() || y < 0 || y >= buffer.size()) return;
	if (buffer[y][x] == fillColor || buffer[y][x] == boundaryColor) return;

	std::stack<Point2D> stack;
	stack.push(Point2D(x, y));

	while (!stack.empty()) {
		Point2D p = stack.top();
		stack.pop();
		int px = p.getX();
		int py = p.getY();

		if (px >= 0 && px < buffer[0].size() && py >= 0 && py < buffer.size() && buffer[py][px] != boundaryColor && buffer[py][px] != fillColor) {
			buffer[py][px] = fillColor;

			stack.push(Point2D(px + 1, py));
			stack.push(Point2D(px - 1, py));
			stack.push(Point2D(px, py + 1));
			stack.push(Point2D(px, py - 1));
		}
	}
}
