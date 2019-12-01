//
// Created by rainer on 24.11.19.
//

#include "Matrix.h"

Matrix::Matrix(int n, int i) {
    m.assign(n, Tuple(i));
}

bool Matrix::equals(Matrix n) const {
    if (m.size() != n.size())
        return false;

    for (std::vector<int>::size_type i = 0; i != m.size(); i++) {
        if (m[i] != n[i])return false;
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
