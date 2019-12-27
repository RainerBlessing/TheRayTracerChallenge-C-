//
// Created by rainer on 13.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_POINT_H
#define RAY_TRACER_CHALLENGE_POINT_H


#include "Tuple.h"
#include "Vector.h"

class Point : public Tuple{
public:
    Point(double x, double y, double z);
    Point();
    Point subtract(Point point) const;
    Point operator - (Point point) const;
    Point subtract(Vector point) const;

    Point add(Vector tuple) const;
    Point operator + (Point point) const;

    double dot(Point point);
};


#endif //RAY_TRACER_CHALLENGE_POINT_H
