#ifndef SPHERE_H
#define SPHERE_H

#include <eigen3/Eigen/Dense>
#include "../ray.h"
#include "hittable.h"


class Sphere : public Hittable {
public:
    Sphere(const Eigen::Vector3f& center, float radius) : center(center), radius(radius) {}

    virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& hit_record) const override;

    Eigen::Vector3f get_center() const { return center; }
    float get_radius() const { return radius; }

private:
    Eigen::Vector3f center;
    float radius;
};

#endif