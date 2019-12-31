//
// Created by rainer on 29.12.19.
//

#include <random>
#include "Object.h"

bool Object::operator==(const Object o) const {
    return o.id == this->id;
}

Object::Object() {
    this->id = getRandomNumber();
}

const int Object::getRandomNumber() const {
    std::random_device rd;
    std::mt19937 eng(rd());
    long int randMax = 30000000;
    long int randMin = 1000000;
    std::uniform_int_distribution<> distr(randMin, randMax);
    return distr(eng);
}
