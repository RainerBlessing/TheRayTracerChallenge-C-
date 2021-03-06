#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE RayTracerChallengeTests
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <shared/Point.h>
#include <shared/Ray.h>
#include <shared/Output.h>
#include <shared/Position.h>
#include <shared/Scaling.h>

BOOST_AUTO_TEST_SUITE(rays_suite)

    BOOST_AUTO_TEST_CASE(creating_and_querying_a_ray_test) {
        auto origin = Point(1, 2, 3);
        auto direction = Vector(4,5,6);

        auto ray = Ray(origin, direction);

        BOOST_CHECK_EQUAL(ray.origin, origin);
        BOOST_CHECK_EQUAL(ray.direction, direction);

    }

    BOOST_AUTO_TEST_CASE(computing_a_point_from_a_distance_test) {

        auto r = Ray(Point(2, 3,4), Vector(1,0,0));


        BOOST_CHECK_EQUAL(Position(r,0),Point(2,3,4));
        BOOST_CHECK_EQUAL(Position(r,1),Point(3,3,4));
        BOOST_CHECK_EQUAL(Position(r,-1),Point(1,3,4));
        BOOST_CHECK_EQUAL(Position(r,2.5),Point(4.5,3,4));

    }

    BOOST_AUTO_TEST_CASE(translating_a_ray_test) {

        auto ray = Ray(Point(1,2,3), Vector(0,1,0));
        auto m = Translation(3,4,5);

        auto r2 = ray.transform(m);

        BOOST_CHECK_EQUAL(r2.origin, Point(4,6,8));
        BOOST_CHECK_EQUAL(r2.direction, Vector(0,1,0));

    }

    BOOST_AUTO_TEST_CASE(scaling_a_ray_test) {

        auto ray = Ray(Point(1,2,3), Vector(0,1,0));
        auto m = Scaling(2,3,4);

        auto r2 = ray.transform(m);

        BOOST_CHECK_EQUAL(r2.origin, Point(2,6,12));
        BOOST_CHECK_EQUAL(r2.direction, Vector(0,3,0));

    }

BOOST_AUTO_TEST_SUITE_END()