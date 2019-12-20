#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <shared/Point.h>
#include <shared/Translation.h>
#include <shared/Scaling.h>
#include <shared/RotationX.h>
#include <shared/RotationY.h>
#include <shared/RotationZ.h>
#include <shared/Shearing.h>
#include <shared/Canvas.h>
#include <shared/Environment.h>
#include <shared/World.h>

std::ostream &operator<<(std::ostream &out, Translation t) {
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    for (std::vector<int>::size_type i = 0; i < t.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < t.size(); j++) {
            out << t[i][j] << " ";
        }
        std::endl(out);
    }

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, Tuple t) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << t[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, Point t) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << t[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, Vector v) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << v[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

BOOST_AUTO_TEST_SUITE(translation_suite)

    BOOST_AUTO_TEST_CASE(multiplying_by_translation_matrix_test) {
        auto t = Translation(5, -3, 2);
        auto p = Point(-3, 4, 5);

        BOOST_CHECK_EQUAL(Point(2, 1, 7), t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(multiplying_by_inverse_translation_matrix_test) {
        auto t = Translation(5, -3, 2);
        auto inv = t.inverse();
        auto p = Point(-3, 4, 5);

        BOOST_CHECK_EQUAL(Point(-8, 7, 3), inv.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(translation_does_not_affect_vectors_test) {
        auto t = Translation(5, -3, 2);
        auto v = Vector(-3, 4, 5);

        BOOST_CHECK_EQUAL(v, t.multiply(v));

    }

    BOOST_AUTO_TEST_CASE(scaling_matrix_applied_to_a_point_test) {
        auto s = Scaling(2, 3, 4);
        auto p = Point(-4, 6, 8);
        auto pp = Point(-8, 18, 32);

        BOOST_CHECK_EQUAL(pp, s.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(scaling_matrix_applied_to_a_vector_test) {
        auto s = Scaling(2, 3, 4);
        auto v = Vector(-4, 6, 8);
        auto vv = Vector(-8, 18, 32);

        BOOST_CHECK_EQUAL(vv, s.multiply(v));

    }

    BOOST_AUTO_TEST_CASE(multiplying_by_the_inverse_of_a_scaling_matrix_test) {
        auto s = Scaling(2, 3, 4);
        auto inv = s.inverse();
        auto v = Vector(-4, 6, 8);
        auto vv = Vector(-2, 2, 2);

        BOOST_CHECK_EQUAL(vv, inv.multiply(v));

    }

    BOOST_AUTO_TEST_CASE(reflection_is_scaling_by_a_negative_value_test) {
        auto s = Scaling(-1, 1, 1);
        auto p = Point(2, 3, 4);
        auto pp = Point(-2, 3, 4);

        BOOST_CHECK_EQUAL(pp, s.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(rotating_a_point_around_the_x_axis_test) {
        auto p = Point(0, 1, 0);
        auto half_quarter = RotationX(M_PI / 4);
        auto full_quarter = RotationX(M_PI / 2);

        auto ph = Point(0, sqrt(2) / 2, sqrt(2) / 2);
        auto pf = Point(0, 0, 1);

        BOOST_CHECK_EQUAL(ph, half_quarter.multiply(p));
        BOOST_CHECK_EQUAL(pf, full_quarter.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(the_inverse_of_an_x_rotation_rotates_in_the_opposite_direction_test) {
        auto p = Point(0, 1, 0);
        auto half_quarter = RotationX(M_PI / 4);

        auto ph = Point(0, sqrt(2) / 2, -sqrt(2) / 2);

        auto inv = half_quarter.inverse();

        BOOST_CHECK_EQUAL(ph, inv.multiply(p));


    }

    BOOST_AUTO_TEST_CASE(rotating_a_point_around_the_y_axis_test) {
        auto p = Point(0, 0, 1);
        auto half_quarter = RotationY(M_PI / 4);
        auto full_quarter = RotationY(M_PI / 2);

        auto ph = Point(sqrt(2) / 2, 0, sqrt(2) / 2);
        auto pf = Point(1, 0, 0);

        BOOST_CHECK_EQUAL(ph, half_quarter.multiply(p));
        BOOST_CHECK_EQUAL(pf, full_quarter.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(rotating_a_point_around_the_z_axis_test) {
        auto p = Point(0, 1, 0);
        auto half_quarter = RotationZ(M_PI / 4);
        auto full_quarter = RotationZ(M_PI / 2);

        auto ph = Point(-sqrt(2) / 2, sqrt(2) / 2, 0);
        auto pf = Point(-1, 0, 0);

        BOOST_CHECK_EQUAL(ph, half_quarter.multiply(p));
        BOOST_CHECK_EQUAL(pf, full_quarter.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_x_in_proportion_to_y_test) {
        auto t = Shearing(1, 0, 0, 0, 0, 0);

        auto p = Point(2, 3, 4);

        auto pp = Point(5, 3, 4);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_x_in_proportion_to_z_test) {
        auto t = Shearing(0, 1, 0, 0, 0, 0);

        auto p = Point(2, 3, 4);

        auto pp = Point(6, 3, 4);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_y_in_proportion_to_x_test) {
        auto t = Shearing(0, 0, 1, 0, 0, 0);

        auto p = Point(2, 3, 4);

        auto pp = Point(2, 5, 4);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_y_in_proportion_to_z_test) {
        auto t = Shearing(0, 0, 0, 1, 0, 0);

        auto p = Point(2, 3, 4);

        auto pp = Point(2, 7, 4);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_z_in_proportion_to_x_test) {
        auto t = Shearing(0, 0, 0, 0, 1, 0);

        auto p = Point(2, 3, 4);

        auto pp = Point(2, 3, 6);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(a_shearing_transformation_moves_z_in_proportion_to_y_test) {
        auto t = Shearing(0, 0, 0, 0, 0, 1);

        auto p = Point(2, 3, 4);

        auto pp = Point(2, 3, 7);

        BOOST_CHECK_EQUAL(pp, t.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(individual_transformations_are_applied_in_sequence_test) {
        auto p = Point(1, 0, 1);
        auto A = RotationX(M_PI / 2);
        auto B = Scaling(5, 5, 5);
        auto C = Translation(10, 5, 7);

        auto p2 = A.multiply(p);

        BOOST_CHECK_EQUAL(p2, Point(1, -1, 0));

        auto p3 = B.multiply(p2);

        BOOST_CHECK_EQUAL(p3, Point(5, -5, 0));

        auto p4 = C.multiply(p3);

        BOOST_CHECK_EQUAL(p4, Point(15, 0, 7));
    }

    BOOST_AUTO_TEST_CASE(chained_transformations_must_be_applied_in_reverse_order_test) {
        auto p = Point(1, 0, 1);
        auto A = RotationX(M_PI / 2);
        auto B = Scaling(5, 5, 5);
        auto C = Translation(10, 5, 7);

        auto T = C.multiply(B).multiply(A);

        BOOST_CHECK_EQUAL(T.multiply(p), Point(15, 0, 7));
    }

    BOOST_AUTO_TEST_CASE(watchface_test) {
        int width = 500;
        int height = 500;

        auto c = Canvas(width, height);

        const Color &white = Color(1, 1, 1);

        double radius = 3.0 / 8.0 * width;
        auto scaling = Scaling(radius, 0, radius);

        Tuple twelve = Point(0, 0, 1);
        Tuple center = Point(0, 0, 0);

        int canvas_center = width / 2;

        c.writePixel(center.x + canvas_center, center.z + canvas_center, white);

        for(int i=0;i<12;i++) {
            auto rotation = RotationY(i * M_PI / 6);

            auto hour = rotation.multiply(twelve);

            const Tuple &scaled = scaling.multiply(hour);
            double x = scaled.x + canvas_center;
            double y = scaled.z + canvas_center;

            c.writePixel(x, y, white);

        }


        c.toFile("watchface.ppm");

    }

BOOST_AUTO_TEST_SUITE_END()

