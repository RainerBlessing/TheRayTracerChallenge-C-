//
// Created by rainer on 29.12.19.
//

#include <cstdarg>
#include <algorithm>
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

std::vector<Intersection> Intersections::hit() {
    std::sort(intersections.begin(),intersections.end(),[](const Intersection a, const Intersection b) {return a.t < b.t; });

    std::vector<Intersection> hits;


    for (auto intersection : intersections){
        if(intersection.t>0){
            hits.push_back(intersection);
            break;
        }
    }

    return hits;
}
