//
// Created by rainer on 15.11.19.
//

#include "Vector.h"
#include <cmath>
#include <iostream>

Vector::Vector(double x, double y, double z) : Tuple(x,y,z,1){

}

Vector *Vector::subtract(Vector vector) {
    return new Vector(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

double Vector::magnitude() {
    std::cout << pow(this->x,2)+pow(this->y,2)+pow(this->z,2)<<std::endl;
    return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

Vector *Vector::normalize() {
    double magnitude = this->magnitude();
    return new Vector(this->x / magnitude , this->y / magnitude, this->z / magnitude);
}

double Vector::dot(Vector vector) {
    return this->x * vector.x + this->y * vector.y + this->z * vector.z;
}

Vector *Vector::cross(Vector vector) {
    return new Vector(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);
}

bool Vector::operator==(Vector vector) {
    return true;
}
