//
// Created by rainer on 17.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_WORLD_H
#define RAY_TRACER_CHALLENGE_WORLD_H


#include "Projectile.h"
#include "Environment.h"

class World {
public:
    Projectile tick(Environment env, Projectile proj);
};


#endif //RAY_TRACER_CHALLENGE_WORLD_H
