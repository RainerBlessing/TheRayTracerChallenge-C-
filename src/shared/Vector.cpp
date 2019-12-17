//
// Created by rainer on 15.11.19.
//

#include "Vector.h"
#include <cmath>
#include <iostream>

Vector::Vector(double x, double y, double z) : Tuple(x,y,z,0){

}

Vector::Vector(Tuple tuple) : Tuple(tuple.x,tuple.y,tuple.z,0){

}

Vector *Vector::subtract(Vector vector) {
    return new Vector(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

double Vector::magnitude() {
    return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}

Vector Vector::normalize() {
    double magnitude = this->magnitude();
    return Vector(this->x / magnitude , this->y / magnitude, this->z / magnitude);
}

double Vector::dot(Vector vector) {
    return this->x * vector.x + this->y * vector.y + this->z * vector.z;
}

Vector *Vector::cross(Vector vector) {
    return new Vector(this->y * vector.z - this->z * vector.y, this->z * vector.x - this->x * vector.z, this->x * vector.y - this->y * vector.x);
}


Vector Vector::add(Vector vector) {

    return Vector(Tuple::add(vector));
}

Vector Vector::multiply(double d) {
    return Vector(this->x*d,this->y*d,this->z*d);
}
Vector::Vector() {}