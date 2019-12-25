//
// Created by rainer on 15.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_VECTOR_H
#define RAY_TRACER_CHALLENGE_VECTOR_H


#include <string>
#include "Tuple.h"

class Vector : public Tuple{
public:
    Vector(double x, double y, double z);

    Vector(Tuple tuple);

    Vector();

    Vector add(Vector tuple);
    Vector subtract(Vector vector);
    Vector normalize();
    double magnitude();
    double dot(Vector vector);
    Vector cross(Vector vector);

//    bool operator==(Vector vector) const{
//        Tuple::operator==(vector);
//    }

    Vector multiply(double d);
};

#endif //RAY_TRACER_CHALLENGE_VECTOR_H
