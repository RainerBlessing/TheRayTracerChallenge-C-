#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Point.h>
#include <iostream>
#include "../src/shared/Tuple.h"
#include "Vector.h"


BOOST_AUTO_TEST_SUITE(tuple_suite)

    BOOST_AUTO_TEST_CASE(point_test) {
        auto a = Tuple(4.3, -4.2, 3.1, 1.0);

        BOOST_CHECK_EQUAL(a.x, 4.3);
        BOOST_CHECK_EQUAL(a.y, -4.2);
        BOOST_CHECK_EQUAL(a.z, 3.1);
        BOOST_CHECK_EQUAL(a.w, 1.0);
        BOOST_CHECK_EQUAL(a.type, a.POINT);
        BOOST_CHECK_EQUAL(a.type, !a.VECTOR);
    }

    BOOST_AUTO_TEST_CASE(vector_test) {
        auto a = Tuple(4.3, -4.2, 3.1, 0);

        BOOST_CHECK_EQUAL(a.x, 4.3);
        BOOST_CHECK_EQUAL(a.y, -4.2);
        BOOST_CHECK_EQUAL(a.z, 3.1);
        BOOST_CHECK_EQUAL(a.w, 0.0);
        BOOST_CHECK_EQUAL(a.type, !a.POINT);
        BOOST_CHECK_EQUAL(a.type, a.VECTOR);
    }

    BOOST_AUTO_TEST_CASE(point_create_tuple_0_test) {
        auto a = Tuple(4, -3, 3, 0);
        auto b = Point(4, -3, 3);
        BOOST_TEST(a.equals(b));

    }
    BOOST_AUTO_TEST_CASE(vector_create_tuple_1_test) {
        auto a = Tuple(4, -3, 3, 1);
        auto b = Vector(4, -3, 3);
        BOOST_TEST(a.equals(b));

    }

BOOST_AUTO_TEST_SUITE_END()