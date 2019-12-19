//
// Created by rainer on 19.12.19.
//

#include "RotationZ.h"

RotationZ::RotationZ(double r) {
    m[0] = {cos(r), -sin(r),0,  0};
    m[1] = {sin(r), cos(r), 0, 0};
    m[2] = {0, 0, 1, 0};
    m[3] = {0, 0, 0, 1};
}
