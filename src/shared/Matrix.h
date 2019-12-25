//
// Created by rainer on 24.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_MATRIX_H
#define RAY_TRACER_CHALLENGE_MATRIX_H


#include <vector>
#include "Tuple.h"
#include <iostream>
class Matrix {

public:
    Matrix();
    Matrix(int n, int i);
    Tuple& operator [] (int i){return m[i];}
    Tuple operator [] (int i) const {return m[i];}
    bool operator == (Matrix n) const;
    std::vector<Tuple> m;

    bool equals(Matrix n) const;

    int size() const;

    Matrix multiply(Matrix matrix);

    Tuple multiply(Tuple tuple);

    Matrix transpose();

    static Matrix getIdentity();

    double determinant();

    Matrix submatrix(int row, int column);

    double minor_(int row, int column);

    double cofactor(int row, int column);

    bool invertible();

    Matrix inverse();

};

#endif //RAY_TRACER_CHALLENGE_MATRIX_H
