//
// Created by rainer on 29.12.19.
//

#include "Intersection.h"

Intersection::Intersection(double t, Object object) {
    this->t = t;
    this->object = object;
}

Intersection::Intersection() {

}

bool Intersection::operator==(Intersection i) const {
    return i.t==this->t && i.object==this->object;
}