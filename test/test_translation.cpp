#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <shared/Point.h>
#include <shared/Translation.h>

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
        auto inv = t.invert();
        auto p = Point(-3, 4, 5);

        BOOST_CHECK_EQUAL(Point(-8,7,3), inv.multiply(p));

    }

    BOOST_AUTO_TEST_CASE(translation_does_not_affect_vectors_test) {
        auto t = Translation(5, -3, 2);
        auto v = Vector(-3, 4, 5);

        BOOST_CHECK_EQUAL(v, t.multiply(v));

    }
BOOST_AUTO_TEST_SUITE_END()

