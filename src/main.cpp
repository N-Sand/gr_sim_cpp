#include <iostream>

// custom header files
#include "objects/image.h"
// for saving pngs
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"


// Function which saves image to a png output
void save_image(const Image& image, const std::string& filename) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<uint8_t> data(width * height * 3);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Image::RGB& pixel = image.at(x, y);
            data[(y * width + x) * 3 + 0] = pixel.r;
            data[(y * width + x) * 3 + 1] = pixel.g;
            data[(y * width + x) * 3 + 2] = pixel.b;
        }
    }

    stbi_write_png(filename.c_str(), width, height, 3, data.data(), width * 3);
}


//Main program
int main() {

    int image_width = 1920;
    int image_height = 1080;
    int image_width_geometric_units = 1;
    int image_height_geometric_units = 1;

    Image image(image_width, image_height);

    // do an example test
    for (int y = 0; y < image_height; ++y) {
        for (int x = 0; x < image_width; ++x) {
            Image::RGB& pixel = image.at(x, y);
            pixel.r = 255 * x / image_width;
            pixel.g = 255 * y / image_height;
            pixel.b = 255 * (x + y) / (image_width + image_height);
        }
    }

    // save
    save_image(image, "output.png");





    return 0;
}