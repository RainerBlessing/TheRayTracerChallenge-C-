//
// Created by rainer on 17.11.19.
//

#ifndef CMAKE_BOOST_DEMO_PROJECTILE_H
#define CMAKE_BOOST_DEMO_PROJECTILE_H


#include "Vector.h"
#include "Point.h"

class Projectile{

public:
    Projectile(Vector pVector, Vector vector);

    Projectile(Point position, Vector velocity);

    Point position;
    Vector velocity;
};


#endif //CMAKE_BOOST_DEMO_PROJECTILE_H
