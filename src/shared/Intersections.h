//
// Created by rainer on 29.12.19.
//

#ifndef RAY_TRACER_CHALLENGE_INTERSECTIONS_H
#define RAY_TRACER_CHALLENGE_INTERSECTIONS_H


#include <vector>
#include "Intersection.h"

class Intersections {

public:
    Intersections(int num, ...);

    int count();

    Intersection get(int i);

    std::vector<Intersection> hit();

private:
    std::vector<Intersection> intersections;
};


#endif //RAY_TRACER_CHALLENGE_INTERSECTIONS_H
