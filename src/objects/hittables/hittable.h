#ifndef HITTABLE_H
#define HITTABLE_H

#include "../ray.h"
#include "eigen3/Eigen/Dense"


class HitRecord {
public:

    // t is the distance from the origin of the ray to the object
    double t;
    // p is the point where the ray hits the object
    Eigen::Vector3f p;
    // normal is the normal vector at the point p
    Eigen::Vector3f normal;
};


class Hittable {
public:
    virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& hit_record) const = 0;
};


#endif