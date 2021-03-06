//
// Created by rainer on 18.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_COLOR_H
#define RAY_TRACER_CHALLENGE_COLOR_H


#include "Vector.h"

class Color : public Vector {
public:
    Color(double r, double g, double b);

    double red() { return x; }

    double green() { return y; }

    double blue() { return z; }

    Color operator+(Color color) {
        return Color(this->x + color.x, this->y + color.y, this->z + color.z);
    }

    Color operator-(Color color) {
        return Color(this->x - color.x, this->y - color.y, this->z - color.z);
    }

    Color operator*(double scalar) {
        return Color(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    Color operator*(Color color) {
        return Color(this->x * color.x, this->y * color.y, this->z * color.z);
    }

    std::string toString() const;

    int normalize(double c) const;
};


#endif //RAY_TRACER_CHALLENGE_COLOR_H
