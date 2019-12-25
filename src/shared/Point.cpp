//
// Created by rainer on 13.11.19.
//

#include "Point.h"
#include "Vector.h"

Point::Point(double x, double y, double z) :  Tuple(x,y,z,1) {

}

Point Point::add(Vector tuple) {
    return Point(tuple.x+this->x,tuple.y+this->y,tuple.z+this->z);
}
Point Point::subtract(Point point) {
    return Point(this->x - point.x, this->y - point.y, this->z - point.z);
}
Point Point::subtract(Vector point) {
    return Point(this->x - point.x, this->y - point.y, this->z - point.z);
}

Point::Point():Point(0,0,0) {

}
