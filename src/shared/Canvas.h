//
// Created by rainer on 19.11.19.
//

#ifndef CMAKE_BOOST_DEMO_CANVAS_H
#define CMAKE_BOOST_DEMO_CANVAS_H


#include <vector>
#include "Color.h"
#include <string>

class Canvas {

public:
    Canvas(int width, int height);

    int height;
    int width;


    std::vector<Color> pixels;
    std::vector<Color> getPixels();

    void writePixel(int x, int y, Color color);
    Color& pixelAt(int x, int y);

    std::string toPPM();
    std::string data();
};


#endif //CMAKE_BOOST_DEMO_CANVAS_H
