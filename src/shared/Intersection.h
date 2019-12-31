//
// Created by rainer on 29.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_INTERSECTION_H
#define RAY_TRACER_CHALLENGE_INTERSECTION_H


#include "Object.h"

class Intersection {

public:
    Intersection(double t, Object object);
    Intersection();
    bool operator == (Intersection i) const;
    double t;
    Object object;
};


#endif //RAY_TRACER_CHALLENGE_INTERSECTION_H
