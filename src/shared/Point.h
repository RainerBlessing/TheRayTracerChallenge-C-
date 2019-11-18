//
// Created by rainer on 13.11.19.
//

#ifndef CMAKE_BOOST_DEMO_POINT_H
#define CMAKE_BOOST_DEMO_POINT_H


#include "Tuple.h"
#include "Vector.h"

class Point : public Tuple{
public:
    Point(double x, double y, double z);
    Point();
    Point *subtract(Point point);

    Point *subtract(Vector point);

    Point add(Vector tuple);
};


#endif //CMAKE_BOOST_DEMO_POINT_H
