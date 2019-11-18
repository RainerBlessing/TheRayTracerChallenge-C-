//
// Created by rainer on 17.11.19.
//

#ifndef CMAKE_BOOST_DEMO_WORLD_H
#define CMAKE_BOOST_DEMO_WORLD_H


#include "Projectile.h"
#include "Environment.h"

class World {
public:
    Projectile tick(Environment env, Projectile proj);
};


#endif //CMAKE_BOOST_DEMO_WORLD_H
