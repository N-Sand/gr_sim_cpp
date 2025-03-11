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

    int get_width() const;
    int get_height() const;

private:
    int width_, height_;
    std::vector<RGB> pixels_;
};

#endif // IMAGE_H