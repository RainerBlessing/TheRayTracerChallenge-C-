//
// Created by rainer on 13.11.19.
//

#include "Point.h"
#include "../../test/Vector.h"

Point::Point(double x, double y, double z) :  Tuple(x,y,z,0) {

}

Point *Point::subtract(Point point) {
    return new Point(this->x - point.x, this->y - point.y, this->z - point.z);
}
Point *Point::subtract(Vector point) {
    return new Point(this->x - point.x, this->y - point.y, this->z - point.z);
}
