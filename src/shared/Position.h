//
// Created by rainer on 23.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_POSITION_H
#define RAY_TRACER_CHALLENGE_POSITION_H


#include "Ray.h"

class Position : public Point{

public:
    Position(Ray ray, double t);
};


#endif //RAY_TRACER_CHALLENGE_POSITION_H
