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
    Canvas(int width, int height): Canvas(width, height, Color(0, 0, 0)){};

    Canvas(int i, int i1, Color color);

    int height;
    int width;


    std::vector<Color> pixels;
    std::vector<Color> getPixels();

    void writePixel(int x, int y, Color color);
    Color& pixelAt(int x, int y);

    std::string toPPM() const;
    std::string header() const;
    std::string pixelData() const;

    std::string limitTo70Characters(const std::string &data) const;

    std::string createStringFromPixels() const;

    void toFile(const char *filename) const;
};


#endif //CMAKE_BOOST_DEMO_CANVAS_H
