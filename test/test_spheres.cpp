#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE RayTracerChallengeTests
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <shared/Point.h>
#include <shared/Ray.h>
#include <shared/Sphere.h>
#include <shared/Output.h>
#include <shared/Scaling.h>
#include <shared/Intersections.h>
#include <shared/Canvas.h>
#include <shared/RotationZ.h>
#include <shared/Shearing.h>

BOOST_AUTO_TEST_SUITE(spheres_suite)

    BOOST_AUTO_TEST_CASE(a_ray_intersects_a_sphere_at_two_points_test) {

        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersects(r);

        BOOST_CHECK_EQUAL(xs.size(), 2);
        BOOST_CHECK_EQUAL(xs[0], 4.0);
        BOOST_CHECK_EQUAL(xs[1], 6.0);

    }

    BOOST_AUTO_TEST_CASE(a_ray_intersects_a_sphere_at_a_tangent_test) {

        auto r = Ray(Point(0, 1, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersects(r);

        BOOST_CHECK_EQUAL(xs.size(), 2);
        BOOST_CHECK_EQUAL(xs[0], 5.0);
        BOOST_CHECK_EQUAL(xs[1], 5.0);

    }

    BOOST_AUTO_TEST_CASE(a_ray_misses_a_sphere_test) {

        auto r = Ray(Point(0, 2, -5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersects(r);

        BOOST_CHECK_EQUAL(xs.size(), 0);
    }

    BOOST_AUTO_TEST_CASE(a_ray_originates_inside_a_sphere_test) {

        auto r = Ray(Point(0, 0, 0), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersects(r);

        BOOST_CHECK_EQUAL(xs.size(), 2);
        BOOST_CHECK_EQUAL(xs[0], -1.0);
        BOOST_CHECK_EQUAL(xs[1], 1.0);

    }

    BOOST_AUTO_TEST_CASE(a_sphere_is_behind_a_ray_test) {

        auto r = Ray(Point(0, 0, 5), Vector(0, 0, 1));
        auto s = Sphere();
        auto xs = s.intersects(r);

        BOOST_CHECK_EQUAL(xs.size(), 2);
        BOOST_CHECK_EQUAL(xs[0], -6.0);
        BOOST_CHECK_EQUAL(xs[1], -4.0);

    }

    BOOST_AUTO_TEST_CASE(a_spheres_default_transformation_test) {

        auto s = Sphere();
        Matrix m = s.transform();

        BOOST_CHECK_EQUAL(s.transform(), Matrix::getIdentity());

    }

    BOOST_AUTO_TEST_CASE(changing_a_spheres_transformation_test) {

        auto s = Sphere();
        auto t = Translation(2, 3, 4);
        s.setTransform(t);

        Matrix m = s.transform();

        BOOST_CHECK_EQUAL(s.transform(), t);

    }

    BOOST_AUTO_TEST_CASE(intersecting_a_scaled_sphere_with_a_ray_test) {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();

        s.setTransform(Scaling(2, 2, 2));

        auto xs = s.intersects(r);
        BOOST_CHECK_EQUAL(xs.size(), 2);
        BOOST_CHECK_EQUAL(xs[0], 3);
        BOOST_CHECK_EQUAL(xs[1], 7);
    }

    BOOST_AUTO_TEST_CASE(intersecting_a_translated_sphere_with_a_ray_test) {
        auto r = Ray(Point(0, 0, -5), Vector(0, 0, 1));
        auto s = Sphere();

        s.setTransform(Scaling(5, 0, 0));

        auto xs = s.intersects(r);
        BOOST_CHECK_EQUAL(xs.size(), 0);
    }

    void createSphereImage(Canvas &canvas, const Color &color, Sphere &sphere,
                           const char *filename)  {
        auto canvas_pixels = canvas.width;

        auto wall_z = 10;
        auto wall_size = 7.0;
        auto pixel_size = wall_size / (double)canvas_pixels;
        auto half = wall_size / 2;

        auto ray_origin = Point(0, 0, -5);

        for (int y = 0; y < canvas_pixels; y++) {
            auto world_y = half - pixel_size * y;
            for (int x = 0; x < canvas_pixels; x++) {
                auto world_x = -half + pixel_size * x;
                auto position = Point(world_x, world_y, wall_z);
                auto r = Ray(ray_origin, Vector(position.subtract(ray_origin)).normalize());

                auto xs=sphere.intersects(r);
                if(x%10==0 && y%10==0){
                    std::cout <<" "<< x << " " << y << std::endl;
                }

                if(xs.size()>0){
                    canvas.writePixel(x, y, color);
                }
            }
        }

        canvas.toFile(filename);
    }

    BOOST_AUTO_TEST_CASE(sphere_test) {
        int canvas_pixels = 100;
        auto c = Canvas(canvas_pixels, canvas_pixels);

        auto sphere = Sphere();

        createSphereImage( c, Color(1, 0, 0), sphere, "sphere.ppm");

    }

    BOOST_AUTO_TEST_CASE(sphere_shrink_along_y_axis_test) {
        int canvas_pixels =100;
        auto c = Canvas(canvas_pixels, canvas_pixels);

        auto sphere = Sphere();
        sphere.setTransform(Scaling(1,0.5,1));

        createSphereImage( c, Color(1, 0, 0), sphere, "sphere_shrink_y.ppm");

    }

    BOOST_AUTO_TEST_CASE(sphere_shrink_along_x_axis_test) {
        int canvas_pixels =100;
        auto c = Canvas(canvas_pixels, canvas_pixels);

        auto sphere = Sphere();
        sphere.setTransform(Scaling(0.5,1,1));

        createSphereImage( c, Color(1, 0, 0), sphere, "sphere_shrink_x.ppm");

    }

    BOOST_AUTO_TEST_CASE(sphere_shrink_and_rotate_test) {
        int canvas_pixels =100;
        auto c = Canvas(canvas_pixels, canvas_pixels);

        auto sphere = Sphere();
        sphere.setTransform(RotationZ(M_PI/4).multiply(Scaling(0.5,1,1)));

        createSphereImage(c, Color(1, 0, 0), sphere, "sphere_shrink_and_rotate.ppm");

    }

    BOOST_AUTO_TEST_CASE(sphere_shrink_and_skew_test) {
        int canvas_pixels =100;
        auto c = Canvas(canvas_pixels, canvas_pixels);

        auto sphere = Sphere();
        sphere.setTransform(Shearing(1,0,0,0,0,0).multiply(Scaling(0.5,1,1)));

        createSphereImage( c, Color(1, 0, 0), sphere, "sphere_shrink_and_skew.ppm");

    }

BOOST_AUTO_TEST_SUITE_END()