//
// Created by rainer on 17.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_PROJECTILE_H
#define RAY_TRACER_CHALLENGE_PROJECTILE_H


#include "Vector.h"
#include "Point.h"

class Projectile{

public:
    Projectile(Vector pVector, Vector vector);

    Projectile(Point position, Vector velocity);

    Point position;
    Vector velocity;
};


#endif //RAY_TRACER_CHALLENGE_PROJECTILE_H
