#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Point.h>
#include <iostream>
#include <cmath>
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

    BOOST_AUTO_TEST_CASE(tuple_addition_test) {
        auto a1 = Tuple(3, -2, 5, 1);
        auto b1 = Tuple(-2, 3, 1, 0);
        auto c = a1.add(b1);

        BOOST_TEST(a1.add(b1)->equals(Tuple(1, 1, 6, 1)));
    }

    BOOST_AUTO_TEST_CASE(point_subtraction_test) {
        auto p1 = Point(3, 2, 1);
        auto p2 = Point(5, 6, 7);
        auto c = p1.subtract(p2);

        BOOST_TEST(p1.subtract(p2)->equals(Point(-2,-4,-6)));
    }

    BOOST_AUTO_TEST_CASE(vector_point_subtraction_test) {
        auto p1 = Point(3, 2, 1);
        auto p2 = Vector(5, 6, 7);
        auto c = p1.subtract(p2);

        BOOST_TEST(p1.subtract(p2)->equals(Point(-2,-4,-6)));
    }

    BOOST_AUTO_TEST_CASE(vector_vector_subtraction_test) {
        auto p1 = Vector(3, 2, 1);
        auto p2 = Vector(5, 6, 7);
        auto c = p1.subtract(p2);
        std::cout <<c->x<<std::endl;
        std::cout <<c->y<<std::endl;
        std::cout <<c->z<<std::endl;

        BOOST_TEST(p1.subtract(p2)->equals(Vector(-2,-4,-6)));
    }

    BOOST_AUTO_TEST_CASE(tuple_negation_test) {
        auto a = Tuple(1,-2,3,-4);

        BOOST_TEST(a.negate()->equals(Tuple(-1,2,-3,4)));
    }

    BOOST_AUTO_TEST_CASE(multiplying_tuple_by_scalar_test) {
        auto a = Tuple(1,-2,3,-4);
        auto b = a.multiply(3.5);

        BOOST_TEST(b->equals(Tuple(3.5,-7,10.5,-14)));
    }

    BOOST_AUTO_TEST_CASE(multiplying_tuple_by_fraction_test) {
        auto a = Tuple(1,-2,3,-4);
        auto b = a.multiply(0.5);

        BOOST_TEST(b->equals(Tuple(0.5,-1,1.5,-2)));
    }

    BOOST_AUTO_TEST_CASE(divide_a_tuple_by_a_scaler_test) {
        auto a = Tuple(1,-2,3,-4);
        auto b = a.divide(2);

        BOOST_TEST(b->equals(Tuple(0.5,-1,1.5,-2)));
    }

    BOOST_AUTO_TEST_CASE(computing_the_magnitude_of_vector_1_0_0_test) {
        auto a = Vector(1,0,0);


        BOOST_CHECK_EQUAL(a.magnitude(),1);
    }

    BOOST_AUTO_TEST_CASE(computing_the_magnitude_of_vector_m1_m20_m3_test) {
        auto a = Vector(-1,-2,-3);


        BOOST_CHECK_EQUAL(a.magnitude(),sqrt(14));
    }

    BOOST_AUTO_TEST_CASE(normalizing_vector_4_0_0_test) {
        auto a = Vector(4,0,0);

        BOOST_TEST(a.normalize()->equals(Vector(1,0,0)));
    }

    BOOST_AUTO_TEST_CASE(dot_product_of_two_tuples_test) {
        auto a = Vector(1,2,3);
        auto b = Vector(2,3,4);


        BOOST_CHECK_EQUAL(a.dot(b),20);
    }

    BOOST_AUTO_TEST_CASE(cross_product_of_two_tuples_test) {
        auto a = Vector(1,2,3);
        auto b = Vector(2,3,4);


        BOOST_TEST(a.cross(b)->equals(Vector(-1,2,-1)));
    }
BOOST_AUTO_TEST_SUITE_END()