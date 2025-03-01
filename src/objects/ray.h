#ifndef RAY_H
#define RAY_H

#include <eigen3/Eigen/Dense>

class Ray {
public:
    Ray();
    Ray(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction);

    const Eigen::Vector3f& origin() const;
    const Eigen::Vector3f& direction() const;
    Eigen::Vector3f at(float t) const;

private:
    Eigen::Vector3f origin_;
    Eigen::Vector3f direction_;
};

#endif // RAY_H