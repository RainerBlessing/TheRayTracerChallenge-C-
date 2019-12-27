//
// Created by rainer on 27.12.19.
//

#include <vector>
#include "Sphere.h"
#include "Ray.h"

std::vector<double> Sphere::intersects(Ray ray) {
    std::vector<double> intersections;

    auto sphere_to_ray = ray.origin - Point(0, 0, 0);
    auto a = ray.direction.dot(ray.direction);
    auto b = 2 * ray.direction.dot(sphere_to_ray);
    auto c = sphere_to_ray.dot(sphere_to_ray) - 1;

    auto discriminant = b*b-4*a*c;

    if(discriminant>=0){
        intersections.push_back((-b-sqrt(discriminant))/(2*a));
        intersections.push_back((-b+sqrt(discriminant))/(2*a));
    }

    return intersections;
}