#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include "Point2D.h"
#include "LineSegment.h"
#include <vector>

class PrimitiveRenderer {
public:
	void rysujPunkt(std::vector<std::vector<int>>& buffer, const Point2D& point, int color);
	void rysujLinia(std::vector<std::vector<int>>& buffer, const LineSegment& line, int color);
	void rysujKwadrat(std::vector<std::vector<int>>& buffer, const std::vector<Point2D>& points, int color);
	void rysujKolo(std::vector<std::vector<int>>& buffer, const Point2D& center, int radius, int color);
	
	void wypelnijFloodFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int backgroundColor);
	void wypelnijBoundaryFill(std::vector<std::vector<int>>& buffer, int x, int y, int fillColor, int boundaryColor);
};

#endif // PRIMITIVE_RENDERER_H
