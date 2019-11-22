//
// Created by rainer on 18.11.19.
//

#include "Color.h"

Color::Color(double r, double g, double b) : Vector(r, g, b) {

}
int Color::normalize(double c) const {
    if(c>1)c=1;
    if(c<0)c=0;
    c=255*c;
    c = c + 0.5 - (c<0);
    return c>0?(int)c:0;
}
std::string Color::toString() const {
    return std::to_string(normalize(x))+" "+std::to_string(normalize(y))+" "+std::to_string(normalize(z));
}