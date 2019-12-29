//
// Created by rainer on 29.12.19.
//

#include "Object.h"

bool Object::operator==(const Object o) const {
    return &o == this;
}