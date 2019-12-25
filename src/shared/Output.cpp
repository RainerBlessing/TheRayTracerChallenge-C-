#ifndef RAY_TRACER_CHALLENGE_OUTPUT_H
#define RAY_TRACER_CHALLENGE_OUTPUT_H

#include <ostream>
#include "Matrix.h"
#include "Translation.h"
#include "Point.h"
#include "Color.h"

std::ostream &operator<<(std::ostream &out, const Translation t) {
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    for (std::vector<int>::size_type i = 0; i < t.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < t.size(); j++) {
            out << t[i][j] << " ";
        }
        std::endl(out);
    }

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, const Tuple t) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << t[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, const Point t) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << t[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, const Vector v) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << v[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, const Color c) {
    for (std::vector<int>::size_type j = 0; j < 4; j++) {
        out << c[j] << " ";
    }
    std::endl(out);

    return out; // return std::ostream so we can chain calls to operator<<
}

std::ostream &operator<<(std::ostream &out, const Matrix m) {
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    for (std::vector<int>::size_type i = 0; i < m.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < m.size(); j++) {
            out << m[i][j] << " ";
        }
        std::endl(out);
    }

    return out; // return std::ostream so we can chain calls to operator<<
}

#endif //RAY_TRACER_CHALLENGE_OUTPUT_H