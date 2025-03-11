#include <eigen3/Eigen/Dense>
#include <iostream>

#include "camera.h"

Camera::Camera(
    const Eigen::Vector3f& location_middle, 
    const Eigen::Vector3f& direction_vector, 
    const float px_to_units, 
    const int height_pixels,
    const int width_pixels,
    const float focal_length
) : location_middle_(location_middle), direction_vector_(direction_vector.normalized()), 
    px_to_units_(px_to_units), height_pixels_(height_pixels), 
    width_pixels_(width_pixels), focal_length_(focal_length) {

    // Use Z as up vector
    Eigen::Vector3f up(0.0f, 0.0f, 1.0f);  // World up vector (Z-up)
    horizontal_ = direction_vector_.cross(up).normalized();  // Right vector
    vertical_ = horizontal_.cross(direction_vector_).normalized();  // Up vector

    // Scale vectors by viewport size
    float viewport_width = (float)(width_pixels) * px_to_units;
    float viewport_height = (float)(height_pixels) * px_to_units;
    horizontal_ *= viewport_width;
    vertical_ *= viewport_height;

    // clean format
    Eigen::IOFormat CleanFmt(5, 0, ", ", "\n", "[", "]");


    // Calculate upper left corner of viewport
    upper_left_ = location_middle_ + 
                 direction_vector_ * focal_length_ +  // Forward
                 vertical_ * 0.5f -                  // Up half height
                 horizontal_ * 0.5f;                 // Left half width
}

Eigen::Vector3f Camera::get_location_middle() {
    return location_middle_;
};

Eigen::Vector3f Camera::get_direction_vector() {
    return direction_vector_;
};

float Camera::get_focal_length() {
    return focal_length_;
};

float Camera::get_px_to_units() {
    return px_to_units_;
};

int Camera::get_height_pixels() {
    return height_pixels_;
};

int Camera::get_width_pixels() {
    return width_pixels_;
};

Eigen::Vector3f Camera::get_loc_px(int x, int y) {
    return upper_left_ + 
           horizontal_ * (static_cast<float>(x) / static_cast<float>(width_pixels_)) - 
           vertical_ * (static_cast<float>(y) / static_cast<float>(height_pixels_));
}


