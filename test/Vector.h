//
// Created by rainer on 15.11.19.
//

#ifndef CMAKE_BOOST_DEMO_VECTOR_H
#define CMAKE_BOOST_DEMO_VECTOR_H


#include <shared/Tuple.h>

class Vector : public Tuple{
public:
    Vector(double x, double y, double z);
    Vector *subtract(Vector vector);
    Vector *normalize();
    double magnitude();
    double dot(Vector vector);
    Vector *cross(Vector vector);
    bool operator==(Vector vector);
};


#endif //CMAKE_BOOST_DEMO_VECTOR_H
