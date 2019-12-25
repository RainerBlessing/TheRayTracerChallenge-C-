//
// Created by rainer on 19.11.19.
//

#include <cstring>
#include <fstream>
#include "Canvas.h"


std::vector<Color> Canvas::getPixels() {
    return pixels;
}

void Canvas::writePixel(int x, int y, Color color) {

    int position = (width * y) + x;

    if (pixels.size() > position) {
        pixels.at(position) = color;
    }
}

Color &Canvas::pixelAt(int x, int y) {
    int position = (width * y) + x;

    return pixels.at(position);
}

std::string Canvas::toPPM() const {
    std::string fileData = header();
    fileData += pixelData();

    return fileData;
}

std::string Canvas::pixelData() const {

    return limitTo70Characters(createStringFromPixels());
}

std::string Canvas::createStringFromPixels() const {
    std::string data = "";

    for (int i = 1; i <= pixels.size(); i++) {
        data += pixels[i - 1].toString();

        if (i > 0 && i % width == 0) {
            data += "\n";
        } else {
            data += " ";
        }
    }
    return data;
}

std::string Canvas::limitTo70Characters(const std::string &data) const {
    std::string newData = std::string(data);

    int i = 0;
    int j = 0;
    int newLine = 0;
    while (i < data.length()) {
        newLine = data.find("\n", i + 1);
        i += 70;
        if (newLine > i) {
            if (i < data.length()) {
                j = i;
                while (data[j] != ' ' && j > 0) {
                    j--;
                }
                if (j > 0) {
                    newData[j] = '\n';
                }
            }

        } else {
            i = newLine;
        }
    }
    return newData;
}

Canvas::Canvas(int width, int height, Color color) {
    this->width = width;
    this->height = height;

    pixels.assign(height * width, color);

}

std::string Canvas::header() const {
    std::string header = "P3\n";
    header += std::to_string(width) + " " + std::to_string(height) + "\n";
    header += std::to_string(255) + "\n";

    return header;
}

void Canvas::toFile(const char *filename) const {
    std::ofstream file;
    file.open (filename);
    file << this->toPPM();
    file.close();
}