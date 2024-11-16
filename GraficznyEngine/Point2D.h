

#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>

#define M_PI 3.14159265358979323846 

class Point2D {
public:
    Point2D(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void translacja(float tx, float ty) {
        x += tx;
        y += ty;
    }

    void rotacja(float alpha) {
        float rad = alpha * M_PI / 180.0;
        float newX = x * cos(rad) - y * sin(rad);
        float newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    void rotacja(float x0, float y0, float alpha) {
        translacja(-x0, -y0);
        rotacja(alpha);
        translacja(x0, y0);
    }

    void skalowanie(float kx, float ky) {
        x *= kx;
        y *= ky;
    }

    void skalowanie(float x0, float y0, float kx, float ky) {
        translacja(-x0, -y0);
        skalowanie(kx, ky);
        translacja(x0, y0);
    }

public:
    float x, y;
};

#endif // POINT2D_H
