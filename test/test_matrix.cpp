#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <shared/Point.h>
#include <iostream>
#include <cmath>
#include <shared/Matrix.h>


BOOST_AUTO_TEST_SUITE(matrix_suite)

    BOOST_AUTO_TEST_CASE(four_4_matrix_test) {
        auto m = Matrix(4, 4);

        m[0] = {1, 2, 3, 4};
        m[1] = {5.5, 6.5, 7.5, 8.5};
        m[2] = {9, 10, 11, 12};
        m[3] = {13.5, 14.5, 15.5, 16.5};

        BOOST_CHECK_EQUAL(m[0][0], 1);
        BOOST_CHECK_EQUAL(m[0][3], 4);
        BOOST_CHECK_EQUAL(m[1][0], 5.5);
        BOOST_CHECK_EQUAL(m[1][2], 7.5);
        BOOST_CHECK_EQUAL(m[2][2], 11);
        BOOST_CHECK_EQUAL(m[3][0], 13.5);
        BOOST_CHECK_EQUAL(m[3][2], 15.5);

    }

    BOOST_AUTO_TEST_CASE(two_2_matrix_test) {
        auto m = Matrix(2, 2);

        m[0] = {-3, 5};
        m[1] = {1, -2};

        BOOST_CHECK_EQUAL(m[0][0], -3);
        BOOST_CHECK_EQUAL(m[0][1], 5);
        BOOST_CHECK_EQUAL(m[1][0], 1);
        BOOST_CHECK_EQUAL(m[1][1], -2);

    }

    BOOST_AUTO_TEST_CASE(three_3_matrix_test) {
        auto m = Matrix(3, 3);

        m[0] = {-3, 5, 0};
        m[1] = {1, -2, -7};
        m[3] = {0, 1, 1};

        BOOST_CHECK_EQUAL(m[0][0], -3);
        BOOST_CHECK_EQUAL(m[0][1], 5);
        BOOST_CHECK_EQUAL(m[1][0], 1);
        BOOST_CHECK_EQUAL(m[1][1], -2);

    }

    BOOST_AUTO_TEST_CASE(matrix_equality_test) {
        auto a = Matrix(4, 4);

        a[0] = {1, 2, 3, 4};
        a[1] = {5, 6, 7, 8};
        a[2] = {9, 8, 7, 6};
        a[3] = {5, 4, 3, 2};

        auto b = Matrix(4, 4);

        b[0] = {1, 2, 3, 4};
        b[1] = {5, 6, 7, 8};
        b[2] = {9, 8, 7, 6};
        b[3] = {5, 4, 3, 2};

        BOOST_TEST(a.equals(b));
    }

    BOOST_AUTO_TEST_CASE(matrix_inequality_test) {
        auto a = Matrix(4, 4);

        a[0] = {1, 2, 3, 4};
        a[1] = {5, 6, 7, 8};
        a[2] = {9, 8, 7, 6};
        a[3] = {5, 4, 3, 2};

        auto b = Matrix(4, 4);

        b[0] = {2, 3, 4, 5};
        b[1] = {6, 7, 8, 9};
        b[2] = {8, 7, 6, 5};
        b[3] = {4, 3, 2, 1};

        BOOST_TEST(!a.equals(b));
    }

    BOOST_AUTO_TEST_CASE(multiplying_two_matrices_test) {
        auto a = Matrix(4, 4);

        a[0] = {1, 2, 3, 4};
        a[1] = {5, 6, 7, 8};
        a[2] = {9, 8, 7, 6};
        a[3] = {5, 4, 3, 2};

        auto b = Matrix(4, 4);

        b[0] = {-2, 1, 2, 3};
        b[1] = {3, 2, 1, -1};
        b[2] = {4, 3, 6, 5};
        b[3] = {1, 2, 7, 8};

        auto c_c = Matrix(4, 4);

        c_c[0] = {20, 22, 50, 48};
        c_c[1] = {44, 54, 114, 108};
        c_c[2] = {40, 58, 110, 102};
        c_c[3] = {16, 26, 46, 42};

        auto c = a.multiply(b);

        BOOST_TEST(c_c.equals(c));
    }

BOOST_AUTO_TEST_SUITE_END()