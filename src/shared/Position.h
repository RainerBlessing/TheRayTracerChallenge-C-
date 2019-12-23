//
// Created by rainer on 23.12.19.
//

#ifndef CMAKE_BOOST_DEMO_POSITION_H
#define CMAKE_BOOST_DEMO_POSITION_H


#include "Ray.h"

class Position : public Point{

public:
    Position(Ray ray, double t);
};


#endif //CMAKE_BOOST_DEMO_POSITION_H
