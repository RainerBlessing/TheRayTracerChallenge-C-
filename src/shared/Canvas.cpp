//
// Created by rainer on 19.11.19.
//

#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;

    this->pixels.assign(height * width, Color(0, 0, 0));

}

std::vector<Color> Canvas::getPixels() {
    return pixels;
}

void Canvas::writePixel(int x, int y, Color color) {
    pixels.at((width * y)+x) = color;
}

Color &Canvas::pixelAt(int x, int y) {
    return pixels.at(x * y);
}

std::string Canvas::toPPM() {
    std::string header = "P3\n";
    header += std::to_string(width) + " " + std::to_string(height) + "\n";
    header += std::to_string(255) + "\n";

    return header;
}

std::string Canvas::data() {
    std::string data = "";

    for (int i = 1; i <= pixels.size(); i++) {
        data += pixels[i-1].toString();
        data += (i > 0 && i % width == 0)  ? "\n" : " ";
    }

    return data;
}
