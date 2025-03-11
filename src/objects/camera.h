#ifndef CAMERA_H_
#define CAMERA_H_

#include <eigen3/Eigen/Dense>

class Camera {

public:
    Camera(
        const Eigen::Vector3f& location_middle, 
        const Eigen::Vector3f& direction_vector, 
        const float px_to_units, 
        const int height_pixels,
        const int width_pixels,
        const float focal_length
    );


    Eigen::Vector3f get_location_middle();

    Eigen::Vector3f get_direction_vector();

    Eigen::Vector3f get_loc_px(int x, int y);

    float get_focal_length();

    float get_px_to_units();

    int get_height_pixels();

    int get_width_pixels();


private:
    Eigen::Vector3f location_middle_;
    Eigen::Vector3f direction_vector_;
    float px_to_units_;
    int height_pixels_;
    int width_pixels_;
    float fov_;
    float focal_length_;
    Eigen::Vector3f upper_left_;
    Eigen::Vector3f vertical_;
    Eigen::Vector3f horizontal_;
    

};
#endif