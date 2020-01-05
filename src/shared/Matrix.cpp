//
// Created by rainer on 24.11.19.
//

#include "Matrix.h"
#include "Tuple.h"

Matrix::Matrix(int n, int i) {
    m.assign(n, Tuple(i));
}

Matrix::Matrix() : Matrix(4, 4) {
}

bool Matrix::equals(Matrix n) const {
    if (m.size() != n.size())
        return false;

    for (std::vector<int>::size_type i = 0; i != m.size(); i++) {
        if (m[i] != n[i]){
            return false;
        }
    }
    return true;

}

int Matrix::size() const {
    return m.size();
}

bool Matrix::operator==(Matrix n) const {
    return equals(n);
}

Matrix Matrix::multiply(Matrix matrix) {
    auto c = Matrix(4, 4);

    for (std::vector<int>::size_type i = 0; i < 4; i++) {
        for (std::vector<int>::size_type j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (std::vector<int>::size_type k = 0; k < 4; k++) {
                c[i][j] += m[i][k] * matrix[k][j];
            }
        }

    }

    return c;
}

Tuple Matrix::multiply(Tuple tuple) {
    auto c = Tuple();

    for (std::vector<int>::size_type i = 0; i < 4; i++) {
        c[i] = 0;
        for (std::vector<int>::size_type j = 0; j < 4; j++) {
            c[i] += m[i][j] * tuple[j];
        }

    }

    return c;
}

Point Matrix::multiply(Point point) {
    auto c = Point();

    for (std::vector<int>::size_type i = 0; i < 4; i++) {
        c[i] = 0;
        for (std::vector<int>::size_type j = 0; j < 4; j++) {
            c[i] += m[i][j] * point[j];
        }

    }

    return c;
}
Matrix Matrix::transpose() {
    auto c = Matrix(4, 4);

    for (std::vector<int>::size_type i = 0; i < 4; i++) {
        for (std::vector<int>::size_type j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (std::vector<int>::size_type k = 0; k < 4; k++) {
                c[i][j] = m[i][k];
            }
        }

    }

    return c;
}

Matrix Matrix::getIdentity() {

    Matrix a = Matrix();

    a[0] = {1, 0, 0, 0};
    a[1] = {0, 1, 0, 0};
    a[2] = {0, 0, 1, 0};
    a[3] = {0, 0, 0, 1};

    return a;
}

double Matrix::determinant() {

    if(m.size()==2)return m[0][0] * m[1][1] - m[0][1] * m[1][0];

    double determinant=0;

    for (std::vector<int>::size_type i = 0; i < m.size(); i++) {
        determinant += m[0][i]*cofactor(0,i);
    }

    return determinant;
}

Matrix Matrix::submatrix(int row, int column) {
    unsigned long submatrixSize = m.size() - 1;

    auto c = Matrix(submatrixSize, submatrixSize);

    int k, l;
    k = l = 0;

    for (std::vector<int>::size_type i = 0; i < m.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < m.size(); j++) {
            if (j != column &&i != row) {
                c[k][l] = m[i][j];
                l++;
            }

        }

        if (i != row )  {
            k++;
        }

        l = 0;
    }

    return c;
}

double Matrix::minor_(int row, int column) {
    return submatrix(row,column).determinant();
}

double Matrix::cofactor(int row, int column) {
    double sign=1;
    int sum=row+column;
    if(sum>0){
        sign=(row+column)%2==0?1:-1;
    }

    return submatrix(row,column).determinant()*sign;
}

bool Matrix::invertible() {
    return determinant()<0;
}

Matrix Matrix::inverse() {
    auto c = Matrix(4, 4);

    for (std::vector<int>::size_type row = 0; row < m.size(); row++) {
        for (std::vector<int>::size_type column = 0; column < m.size(); column++) {
                c[column][row] = cofactor(row, column) / determinant() ;
        }

    }

    return c;
}