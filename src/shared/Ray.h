//
// Created by rainer on 23.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_RAY_H
#define RAY_TRACER_CHALLENGE_RAY_H


#include "Point.h"

class Ray {

public:
    Ray(Point origin, Vector direction);

    Point origin;
    Vector direction;
};


#endif //RAY_TRACER_CHALLENGE_RAY_H
