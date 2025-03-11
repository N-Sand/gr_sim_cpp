#include "sphere.h"
#include "hittable.h"
#include "../ray.h"
#include <cmath>
#include <eigen3/Eigen/Dense>

bool Sphere::hit(const Ray& ray, float t_min, float t_max, HitRecord& hit_record) const {
    Eigen::Vector3f oc = ray.origin() - center;
    float a = ray.direction().dot(ray.direction());
    float b = 2.0 * oc.dot(ray.direction());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            hit_record.t = temp;
            hit_record.p = ray.at(temp);
            hit_record.normal = (hit_record.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            hit_record.t = temp;
            hit_record.p = ray.at(temp);
            hit_record.normal = (hit_record.p - center) / radius;
            return true;
        }
    }
    return false;
}