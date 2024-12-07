#include "img/ppm.hpp"
#include "img/rgb_pixel.hpp"
#include "raylib.h"
#include <vector>

int main() {
  SetTraceLogLevel(LOG_NONE);
  // InitWindow(800, 600, "Raylib Window");
  /*
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
      EndDrawing();
    }
  */
  int image_width = 256;
  int image_height = 256;
  std::vector<std::vector<rgb_pixel>> data(
      image_height, std::vector<rgb_pixel>(image_width, {0, 0, 0}));
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      size_t ir = int(255.999 * r);
      size_t ig = int(255.999 * g);
      size_t ib = int(255.999 * b);
      data[j][i] = {ir, ig, ib};
    }
  }
  ppm img(image_height, image_width, std::move(data));
  img.writeImgFile("out.ppm");

  // CloseWindow();
  return 0;
}