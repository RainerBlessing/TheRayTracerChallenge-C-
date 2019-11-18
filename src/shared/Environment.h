//
// Created by rainer on 17.11.19.
//

#ifndef CMAKE_BOOST_DEMO_ENVIRONMENT_H
#define CMAKE_BOOST_DEMO_ENVIRONMENT_H


#include "Vector.h"

class Environment {

public:
    Environment(Vector gravity, Vector wind);

    Vector gravity;
    Vector wind;
};


#endif //CMAKE_BOOST_DEMO_ENVIRONMENT_H
