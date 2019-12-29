//
// Created by rainer on 29.12.19.
//

#include <cstdarg>
#include "Intersections.h"
#include "Intersection.h"

int Intersections::count() {
    return intersections.size();
}

Intersections::Intersections(int num ...) {
    va_list valist;

    va_start(valist, num);

    for (int i = 0; i < num; i++) {

        Intersection *pIntersection = va_arg(valist, Intersection*);
        intersections.push_back(*pIntersection);
    }

    va_end(valist);

}

Intersection Intersections::get(int i) {
    return intersections[i];
}
