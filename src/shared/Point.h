//
// Created by rainer on 13.11.19.
//

#ifndef CMAKE_BOOST_DEMO_POINT_H
#define CMAKE_BOOST_DEMO_POINT_H


#include "Tuple.h"
#include "../../test/Vector.h"

class Point : public Tuple{
public:
    Point(double x, double y, double z);
    Point *subtract(Point point);

    Point *subtract(Vector point);
};


#endif //CMAKE_BOOST_DEMO_POINT_H
