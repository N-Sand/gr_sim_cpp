#ifndef HITTABLE_ARRAY_H
#define HITTABLE_ARRAY_H

#include "hittable.h"
#include <vector>
#include <memory>

class HittableArray : public Hittable {

public:
    HittableArray() = default;
    HittableArray(std::vector<std::shared_ptr<Hittable>> hittables) : hittables(hittables) {}

    void clear() {
        hittables.clear();
    }

    void add(std::shared_ptr<Hittable> hittable) {
        hittables.push_back(hittable);
    }

    virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& hit_record) const override {
        HitRecord temp_hit_record;
        bool hit_anything = false;
        float closest_so_far = t_max;

        for (const auto& hittable : hittables) {
            if (hittable->hit(ray, t_min, closest_so_far, temp_hit_record)) {
                hit_anything = true;
                closest_so_far = temp_hit_record.t;
                hit_record = temp_hit_record;
            }
        }

        return hit_anything;
    }

    std::vector<std::shared_ptr<Hittable>> hittables;
};


#endif