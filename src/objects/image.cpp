#include <vector>
#include <stdexcept>

#include "image.h"

Image::RGB::RGB() : r(0), g(0), b(0) {}
Image::RGB::RGB(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

Image::Image(int width, int height) : width(width), height(height), pixels(width * height) {}

Image::RGB& Image::at(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels[y * width + x];
}

const Image::RGB& Image::at(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels[y * width + x];
}

int Image::getWidth() const { return width; }
int Image::getHeight() const { return height; }
