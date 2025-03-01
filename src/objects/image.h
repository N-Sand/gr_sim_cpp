#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <stdexcept>

class Image {
public:
    struct RGB {
        unsigned char r, g, b;
        RGB();
        RGB(unsigned char r, unsigned char g, unsigned char b);
    };

    Image(int width, int height);

    RGB& at(int x, int y);
    const RGB& at(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

private:
    int width, height;
    std::vector<RGB> pixels;
};

#endif // IMAGE_H