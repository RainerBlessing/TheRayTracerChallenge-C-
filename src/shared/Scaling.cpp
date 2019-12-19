//
// Created by rainer on 19.12.19.
//

#include "Scaling.h"

Scaling::Scaling(double x, double y, double z) {
    m[0] = {x, 0, 0, 0};
    m[1] = {0, y, 0, 0};
    m[2] = {0, 0, z, 0};
    m[3] = {0, 0, 0, 1};
}