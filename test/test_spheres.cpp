#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE RayTracerChallengeTests
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <shared/Point.h>
#include <shared/Ray.h>
#include <shared/Sphere.h>

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
BOOST_AUTO_TEST_SUITE_END()