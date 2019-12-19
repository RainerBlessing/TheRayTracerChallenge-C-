//
// Created by rainer on 19.12.19.
//

#include "RotationY.h"

RotationY::RotationY(double r) {
    m[0] = {cos(r), 0, sin(r), 0};
    m[1] = {0, 1, 0, 0};
    m[2] = {-sin(r), 0, cos(r), 0};
    m[3] = {0, 0, 0, 1};
}