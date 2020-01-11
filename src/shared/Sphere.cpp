//
// Created by rainer on 27.12.19.
//

#include <vector>
#include "Sphere.h"
#include "Ray.h"

std::vector<double> Sphere::intersects(Ray ray) {
    std::vector<double> intersections;

    auto ray2 = ray.transform(this->transform().inverse());

    auto sphere_to_ray = ray2.origin - Point(0, 0, 0);
    auto a = ray2.direction.dot(ray2.direction);
    auto b = 2 * ray2.direction.dot(sphere_to_ray);
    auto c = sphere_to_ray.dot(sphere_to_ray) - 1;

    auto discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double d = 2 * a;
        double root_discriminant = sqrt(discriminant);

        intersections.push_back((-b - root_discriminant) / d);
        intersections.push_back((-b + root_discriminant) / d);
    }

    return intersections;
}

Matrix Sphere::transform() {
    return translation;
}

void Sphere::setTransform(Matrix m) {
    this->translation = m;
}

Vector Sphere::normalAt(Point worldPoint) {
    auto sphere_inverse = transform().inverse();
    auto object_point = sphere_inverse.multiply(worldPoint);
    auto object_normal = Vector(object_point - Point(0, 0, 0));
    auto world_normal = sphere_inverse.transpose().multiply(object_normal);
    world_normal.w = 0;

    return Vector(world_normal).normalize();
}
