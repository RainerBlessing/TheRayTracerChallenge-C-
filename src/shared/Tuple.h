//
// Created by rainer on 12.11.19.
//

#ifndef CMAKE_BOOST_DEMO_TUPLE_H
#define CMAKE_BOOST_DEMO_TUPLE_H


class Tuple {

public:
    double x,y,z,w;
    enum Type {POINT=1,VECTOR=0};
    double type;
    Tuple(double x, double y, double z, double w);
    bool equals(Tuple t);

    Tuple* add(Tuple tuple);

    Tuple *subtract(Tuple tuple);

    Tuple *negate();

    Tuple *multiply(double d);

    Tuple* divide(double d);
};


#endif //CMAKE_BOOST_DEMO_TUPLE_H
