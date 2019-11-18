//
// Created by rainer on 12.11.19.
//

#ifndef CMAKE_BOOST_DEMO_TUPLE_H
#define CMAKE_BOOST_DEMO_TUPLE_H


#include <cmath>

class Tuple {

public:
    double x,y,z,w;
    enum Type {POINT=1,VECTOR=0};
    double type;
    Tuple(double x, double y, double z, double w);

    Tuple();

    bool equals(Tuple t);

    Tuple add(Tuple tuple);

    Tuple *subtract(Tuple tuple);

    Tuple *negate();

    Tuple *multiply(double d);

    Tuple* divide(double d);

    bool equal(double a, double b){
        return fabs(a - b) < EPSILON;
    }

    double EPSILON=0.000001;

    bool operator==(Tuple t){
        equals(t);
    }
};


#endif //CMAKE_BOOST_DEMO_TUPLE_H
