//
// Created by rainer on 23.12.19.
//

#include "Ray.h"

Ray::Ray(Point origin, Vector direction) {
    this->origin = origin;
    this->direction = direction;
}

Ray Ray::transform(Matrix m) {
    return Ray(m.multiply(this->origin), m.multiply(this->direction));
}
