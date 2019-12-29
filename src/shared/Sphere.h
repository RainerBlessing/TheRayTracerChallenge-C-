//
// Created by rainer on 27.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_SPHERE_H
#define RAY_TRACER_CHALLENGE_SPHERE_H


#include "Ray.h"
#include "Object.h"

class Sphere : public Object{

public:
    std::vector<double> intersects(Ray ray);
};


#endif //RAY_TRACER_CHALLENGE_SPHERE_H
