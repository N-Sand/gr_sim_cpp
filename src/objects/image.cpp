#include <vector>
#include <stdexcept>

#include "image.h"

Image::RGB::RGB() : r(0), g(0), b(0) {}
Image::RGB::RGB(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

Image::Image(int width, int height) : width_(width), height_(height), pixels_(width * height) {}

Image::RGB& Image::at(int x, int y) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels_[y * width_ + x];
}

const Image::RGB& Image::at(int x, int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels_[y * width_ + x];
}

int Image::get_width() const { return width_; }
int Image::get_height() const { return height_; }
