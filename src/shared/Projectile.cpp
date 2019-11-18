//
// Created by rainer on 17.11.19.
//

#include <iostream>
#include "Projectile.h"
#include "Point.h"

Projectile::Projectile(Point position, Vector velocity) {
    this->position = position;
    this->velocity = velocity;
}
