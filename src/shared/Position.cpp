    //
// Created by rainer on 23.12.19.
//

#include "Position.h"

    Position::Position(Ray ray, double t) {
        auto point = ray.origin.add(ray.direction.multiply(t));

        this->x = point.x;
        this->y = point.y;
        this->z = point.z;
        this->w = point.w;
    }
