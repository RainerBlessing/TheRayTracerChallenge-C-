//
// Created by rainer on 19.12.19.
//

#ifndef CMAKE_BOOST_DEMO_SHEARING_H
#define CMAKE_BOOST_DEMO_SHEARING_H


#include "Matrix.h"

class Shearing  : public Matrix{
public:
    Shearing(double xy, double xz, double yx, double yz, double zx, double zy);
};


#endif //CMAKE_BOOST_DEMO_SHEARING_H
