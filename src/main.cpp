#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <memory>
#include <string>

// custom header files
#include "objects/image.h"
#include "objects/ray.h"
#include "objects/camera.h"
#include "objects/hittables/sphere.h"
#include "objects/hittables/hittable_array.h"

// for saving pngs
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

// https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage/theppmimageformat
// Function which saves image to a png output
void save_image(const Image& image, const std::string& filename) {
    int width = image.get_width();
    int height = image.get_height();
    std::vector<uint8_t> data(width * height * 3);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Image::RGB& pixel = image.at(x, y);
            data[(y * width + x) * 3 + 0] = pixel.r;
            data[(y * width + x) * 3 + 1] = pixel.g;
            data[(y * width + x) * 3 + 2] = pixel.b;
        }
    }

    stbi_write_png(filename.c_str(), width, height, 3, data.data(), width * 3);
}


void render(Camera& camera, const HittableArray& hittables, Image& image, int rays_per_pixel) {

    Eigen::IOFormat CleanFmt(6, Eigen::StreamPrecision, ", ", "\n", "[", "]");

    int image_width = image.get_width();
    int image_height = image.get_height();

    Eigen::Vector3f location_middle = camera.get_location_middle();
    Eigen::Vector3f ray_direction(0.0f, 0.0f, 0.0f);
    HitRecord hit_record;
    

    for (int y = 0; y < image_height; ++y) {
        std::clog << "\rProgress: " << ((float)(image_height - y+1)/(float)image_height) * 100. << ' ' << std::flush;
        for (int x = 0; x < image_width; ++x) {
            Image::RGB& pixel_final = image.at(x, y);
            Eigen::Vector3f pixel(0., 0., 0.);

            for (int i = 0; i < rays_per_pixel; i++) {

                // get the location of the pixel in space + jitter within the pixel boundary
                Eigen::Vector3f loc_px = camera.get_loc_px(x, y) + Eigen::Vector3f::Random() * camera.get_px_to_units();
                //std::cout << "x,y = " << x << "," << y << std::endl;
                //std::cout << "get_loc_px: \n" << camera.get_loc_px(x, y) << std::endl;


                // get the direction of the ray
                ray_direction = loc_px - location_middle;
                ray_direction.normalize();

                // create the ray
                Ray ray(location_middle, ray_direction);

                //std::cout << "ray direction: " << ray_direction.format(CleanFmt) << loc_px.format(CleanFmt) << location_middle.format(CleanFmt) << std::endl;

                // check if the ray hits any of the hittables
                if (hittables.hit(ray, 0, std::numeric_limits<float>::max(), hit_record)) {
                    //std::cout << "HIT! at point: \n" << hit_record.p.format(CleanFmt) 
                    //<< " with normal: \n" << hit_record.normal.format(CleanFmt) 
                    //<< " at distance: \n" << hit_record.t << std::endl;
                    
                    pixel[0] += 255 * 0.5 * (hit_record.normal.x() + 1);
                    pixel[1] += 255 * 0.5 * (hit_record.normal.y() + 1);
                    pixel[2] += 255 * 0.5 * (hit_record.normal.z() + 1);
                }

            }

            // average over the rays in each pixel (convert to unsigned char)
            pixel_final.r = (unsigned char)(pixel[0] / rays_per_pixel);
            pixel_final.g = (unsigned char)(pixel[1] / rays_per_pixel);
            pixel_final.b = (unsigned char)(pixel[2] / rays_per_pixel);
        }
    }
}


//Main program
int main() {

    int image_width = 400;
    int image_height = 300;
    float image_width_geometric_units = 2;
    int rays_per_pixel = 5;
    float focal_length = 1.0f;

    Image image(image_width, image_height);

    // camera parameters
    Eigen::Vector3f location_middle(0.0f, 5.1f, 0.0f);
    Eigen::Vector3f direction_vector(0.1f, -0.9f, 0.0f);
    float px_to_units = image_width_geometric_units / image_width;


    Camera camera(location_middle, direction_vector, px_to_units, image_height, image_width, focal_length);

    // make hittable array
    std::vector<std::shared_ptr<Hittable>> hittables;
    hittables.push_back(std::make_shared<Sphere>(Eigen::Vector3f(0.0f, 0.0f, 0.0f), 1.0f));
    hittables.push_back(std::make_shared<Sphere>(Eigen::Vector3f(0.0f, 0.0f, -105.0f), 100.0f));
    HittableArray hittables_array(hittables);

    // render
    render(camera, hittables, image, rays_per_pixel);

    // save
    save_image(image, "output.png");


    return 0;
}