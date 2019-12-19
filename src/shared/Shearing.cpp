//
// Created by rainer on 19.12.19.
//

#include "Shearing.h"

Shearing::Shearing(double xy, double xz, double yx, double yz, double zx, double zy) {
    m[0] = {1, xy, xz, 0};
    m[1] = {yx, 1, yz, 0};
    m[2] = {zx, zy, 1, 0};
    m[3] = {0, 0, 0, 1};
}
