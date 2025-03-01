#include <iostream>
#include <eigen3/Eigen/Dense>

#include "ray.h"

Ray::Ray() : origin_(Eigen::Vector3f::Zero()), direction_(Eigen::Vector3f::Zero()) {}

Ray::Ray(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction) : origin_(origin), direction_(direction) {}

const Eigen::Vector3f& Ray::origin() const { 
    return origin_; 
}

const Eigen::Vector3f& Ray::direction() const { 
    return direction_; 
}

Eigen::Vector3f Ray::at(float t) const { 
    return origin_ + t * direction_; 
}


