//
// Created by rainer on 23.12.19.
//

#ifndef CMAKE_BOOST_DEMO_RAY_H
#define CMAKE_BOOST_DEMO_RAY_H


#include "Point.h"

class Ray {

public:
    Ray(Point origin, Vector direction);

    Point origin;
    Vector direction;
};


#endif //CMAKE_BOOST_DEMO_RAY_H
