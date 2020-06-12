#include "tgaimage.h"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

float interpolate(int& x0, int& x1, float& ratio) {
    return x0 + (x1 - x0) * ratio;
}

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    int x;
    int y;
    for (float t = 0.0; t < 1.0; t += 0.01) {
        x = interpolate(x0, x1, t);
        y = interpolate(y0, y1, t);
        image.set(x, y, color);
    }

}




int main(int argc, char** argv) {
        TGAImage image(100, 100, TGAImage::RGB);
        image.set(52, 41, red);
        image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
        image.write_tga_file("output1.tga");

        TGAImage im2 = TGAImage(100, 100, TGAImage::RGB);
        line(39, 23, 80, 40, im2, red);
        im2.flip_vertically();
        im2.write_tga_file("output2.tga");




        return 0;
}