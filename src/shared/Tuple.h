//
// Created by rainer on 12.11.19.
//

#ifndef RAY_TRACER_CHALLENGE_TUPLE_H
#define RAY_TRACER_CHALLENGE_TUPLE_H


#include <cmath>
#include "Utility.h"

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
        return !(round5(n.x) == round5(x) && round5(n.y) == round5(y) && round5(n.z) == round5(z) &&
                 round5(n.w) == round5(w));
    };

    bool equals(Tuple t) const;

    Tuple add(Tuple tuple);

    Tuple subtract(Tuple tuple);

    Tuple negate();

    Tuple multiply(double d);

    Tuple divide(double d);

    bool equal(double a, double b) const {
        return fabs(round5(a) - round5(b)) < EPSILON;
    }

    double EPSILON = 0.000001;

    bool operator==(Tuple t) const {
        equals(t);
    }
};


#endif //RAY_TRACER_CHALLENGE_TUPLE_H
