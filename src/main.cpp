#include "img/ppm.hpp"
#include "img/ray.hpp"
#include "utility/color.hpp"
#include "utility/vec3.hpp"
#include <algorithm>
#include <stdint.h>
#include <vector>

namespace RL {
#include "raylib.h"
}

Util::Color<double> ray_color(const Ray<double> &r) {
  return Util::Color<double>(0, 0, 0);
}

int main() {
  RL::SetTraceLogLevel(RL::LOG_NONE);
  // InitWindow(800, 600, "Raylib Window");
  /*
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
      EndDrawing();
    }
  */
  constexpr double aspect_ration = 16.0 / 9.0;
  size_t image_width = 400;
  size_t image_height = static_cast<int>(image_width / aspect_ration);
  image_height = (image_height < 1) ? 1 : image_height;

  // camera
  constexpr double focal_length = 1.0;
  double viewport_height = 2.0;
  double viewport_width =
      viewport_height * (static_cast<double>(image_width) / image_height);
  // y-axis goes up, x-axis to the right, negative z-axis points int the viewing
  // direction
  Util::Vec3<double> cam_center{0, 0, 0};
  // vectors accross and down the viewport
  Util::Vec3<double> viewport_u{viewport_width, 0, 0};
  Util::Vec3<double> viewport_v{0, -viewport_height, 0};
  // Calculate the horizontal and vertical delta vectors from pixel to pixel.
  auto pixel_delta_u = viewport_u / static_cast<double>(image_width);
  auto pixel_delta_v = viewport_v / static_cast<double>(image_height);
  // Calc location of upper left pixel
  auto viewport_upper_left = cam_center -
                             Util::Vec3<double>(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc = viewport_upper_left + .5 * (pixel_delta_u + pixel_delta_v);

  std::vector<std::vector<Util::Color<double>>> data(
      image_height, std::vector<Util::Color<double>>(image_width, {0, 0, 0}));
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (pixel_delta_u * i) + (pixel_delta_v * j);
      auto ray_dir = pixel_center - cam_center;
      Ray<double> r(cam_center, ray_dir);
      data[j][i] = ray_color(r);
    }
  }
  ppm<double> img(image_height, image_width, std::move(data));
  img.writeImgFile("out.ppm");

  // CloseWindow();
  return 0;
}