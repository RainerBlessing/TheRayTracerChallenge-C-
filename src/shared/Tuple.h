//
// Created by rainer on 12.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_TUPLE_H
#define RAY_TRACER_CHALLENGE_TUPLE_H


#include <cmath>

class Tuple {

public:
    Tuple(int i);

    double x, y, z, w;
    enum Type {
        POINT = 1, VECTOR = 0
    };
    double type;

    Tuple(double x, double y, double z, double w);

    Tuple(double x, double y, double z);

    Tuple(double x, double y);

    Tuple();

    double &operator[](int i) {
        switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
        }
        return reinterpret_cast<double &>(nanl);
    }

    double operator[](int i) const {
        switch (i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
        }
        return reinterpret_cast<double &>(nanl);
    }

    bool operator!=(Tuple n) const {
        bool unequal = true;

        if (std::round(n.x) == std::round(x)) { unequal = false;};
        if (std::round(n.y) == std::round(y)) { unequal = false;};
        if (std::round(n.z) == std::round(z)) { unequal = false;};
        if (std::round(n.w) == std::round(w)) { unequal = false;};

        return unequal;
    };

    bool equals(Tuple t) const;

    Tuple add(Tuple tuple);

    Tuple subtract(Tuple tuple);

    Tuple negate();

    Tuple multiply(double d);

    Tuple divide(double d);

    bool equal(double a, double b) const{
        return fabs(a - b) < EPSILON;
    }

    double EPSILON = 0.000001;

    bool operator==(Tuple t) const{
        equals(t);
    }
};


#endif //RAY_TRACER_CHALLENGE_TUPLE_H
