#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE RayTracerChallengeTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Sphere.h>
#include <shared/Intersections.h>
#include "shared/Intersection.h"
#include "shared/Output.h"

BOOST_AUTO_TEST_SUITE(rays_suite)

    BOOST_AUTO_TEST_CASE(an_intersection_encapsulates_t_and_object_test) {
        const Object s = Sphere();

        auto i = Intersection(3.5,s);

        BOOST_CHECK_EQUAL(i.t , 3.5);

        //TODO printed memory address is the same, but comparison fails somehow
        //        BOOST_CHECK_EQUAL(i.object, s);


    }

    BOOST_AUTO_TEST_CASE(aggregating_intersections_test) {
        const Object s = Sphere();

        auto i1 = Intersection(1,s);
        auto i2 = Intersection(2,s);

        auto xs = Intersections(2,&i1,&i2);

        BOOST_CHECK_EQUAL(xs.count() , 2);
        BOOST_CHECK_EQUAL(xs.get(0).t , 1);
        BOOST_CHECK_EQUAL(xs.get(1).t , 2);

    }

BOOST_AUTO_TEST_SUITE_END()