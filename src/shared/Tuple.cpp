//
// Created by rainer on 12.11.19.
//

#include "Tuple.h"

Tuple::Tuple(double x, double y, double z, double w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    this->type = w;
}

bool Tuple::equals(Tuple t) {
    return t.x == this->x && t.y == this->y && t.z == this->z && t.w == this->w;
}
//
//inline bool operator==(const Tuple &lhs, const Tuple &rhs) {
//    return lhs.x==rhs.x;
//}


