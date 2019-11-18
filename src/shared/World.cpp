//
// Created by rainer on 17.11.19.
//

#include <iostream>
#include "World.h"

Projectile World::tick(Environment env, Projectile proj) {
    Point position = proj.position.add(proj.velocity);
    Vector velocity = proj.velocity.add(env.gravity).add(env.wind);

    return Projectile(position, velocity);
}
