//
// Created by rainer on 17.12.19.
//

#include "Translation.h"

Translation::Translation(double x, double y, double z) {
    m[0] = {1, 0, 0, x};
    m[1] = {0, 1, 0, y};
    m[2] = {0, 0, 1, z};
    m[3] = {0, 0, 0, 1};
}
