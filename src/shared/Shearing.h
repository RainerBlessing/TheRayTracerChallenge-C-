//
// Created by rainer on 19.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_SHEARING_H
#define RAY_TRACER_CHALLENGE_SHEARING_H


#include "Matrix.h"

class Shearing  : public Matrix{
public:
    Shearing(double xy, double xz, double yx, double yz, double zx, double zy);
};


#endif //RAY_TRACER_CHALLENGE_SHEARING_H
