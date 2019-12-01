//
// Created by rainer on 12.11.19.
//

#include "Tuple.h"

Tuple::Tuple(double x, double y, double z, double w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
    this->type = w;
}

bool Tuple::equals(Tuple t) {
    return equal(t.x,this->x)   && equal(t.y,this->y) && equal(t.z,this->z) ;
}

Tuple Tuple::add(Tuple tuple) {
    return Tuple(tuple.x+this->x,tuple.y+this->y,tuple.z+this->z,tuple.w+this->w);
}

Tuple* Tuple::subtract(Tuple tuple) {
    return new Tuple(tuple.x-this->x,tuple.y-this->y,tuple.z-this->z,tuple.w-this->w);
}

Tuple* Tuple::negate() {
    return new Tuple(this->x*-1,this->y*-1,this->z*-1,this->w*-1);
}

Tuple* Tuple::multiply(double d) {
    return new Tuple(this->x*d,this->y*d,this->z*d,this->w*d);
}

Tuple* Tuple::divide(double d) {
    return new Tuple(this->x/d,this->y/d,this->z/d,this->w/d);;
}

Tuple::Tuple() :Tuple(4){}

Tuple::Tuple(int i) {

}

Tuple::Tuple(double x, double y):Tuple(x,y,0) {

}

Tuple::Tuple(double x, double y, double z) :Tuple(x,y,z,0) {

}


