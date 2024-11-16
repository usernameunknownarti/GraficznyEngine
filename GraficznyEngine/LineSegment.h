

#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"

class LineSegment {
public:
    LineSegment(const Point2D& start, const Point2D& end) : start(start), koniec(end) {}

    const Point2D& getStart() const { return start; }
    const Point2D& getEnd() const { return koniec; }

    void translacja(float tx, float ty) {
        start.translacja(tx, ty);
        koniec.translacja(tx, ty);
    }

    void rotacja(float alpha) {
        start.rotacja(alpha);
        koniec.rotacja(alpha);
    }

    void rotacja(float x0, float y0, float alpha) {
        start.rotacja(x0, y0, alpha);
        koniec.rotacja(x0, y0, alpha);
    }

    void skalowanie(float kx, float ky) {
        start.skalowanie(kx, ky);
        koniec.skalowanie(kx, ky);
    }

    void skalowanie(float x0, float y0, float kx, float ky) {
        start.skalowanie(x0, y0, kx, ky);
        koniec.skalowanie(x0, y0, kx, ky);
    }

private:
    Point2D start;
    Point2D koniec;
};

#endif // LINESEGMENT_H
