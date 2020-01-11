//
// Created by rainer on 27.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_SPHERE_H
#define RAY_TRACER_CHALLENGE_SPHERE_H


#include "Ray.h"
#include "Object.h"

class Sphere : public Object {

public:
    std::vector<double> intersects(Ray ray);

    Matrix transform();

    void setTransform(Matrix m);

    Vector normalAt(Point worldPoint);

private:
    Matrix translation = Matrix::getIdentity();
};


#endif //RAY_TRACER_CHALLENGE_SPHERE_H
