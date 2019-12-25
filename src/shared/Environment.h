//
// Created by rainer on 17.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_ENVIRONMENT_H
#define RAY_TRACER_CHALLENGE_ENVIRONMENT_H


#include "Vector.h"

class Environment {

public:
    Environment(Vector gravity, Vector wind);

    Vector gravity;
    Vector wind;
};


#endif //RAY_TRACER_CHALLENGE_ENVIRONMENT_H
