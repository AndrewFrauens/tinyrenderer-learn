#include <algorithm>
#include <cmath>


#include "tgaimage.h"


TGAColor& const white   = TGAColor(255, 255, 255, 255);
TGAColor& const black   = TGAColor(  0,   0,   0, 255);

TGAColor& const red     = TGAColor(255,   0,   0,  255);
TGAColor& const green   = TGAColor(  0, 255,   0, 255);
TGAColor& const blue    = TGAColor(  0,   0, 255, 255);

TGAColor& const yellow  = TGAColor(255, 255,   0, 255);
TGAColor& const cyan    = TGAColor(  0, 255, 255, 255);
TGAColor& const magenta = TGAColor(255,   0, 255, 255);


void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor &color) {
    bool steep = false;
    if (std::abs(x1 - x0) < std::abs(y1 - y0)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }

    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror2 = std::abs(dy) * 2;
    int error2 = 0;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        if (steep){
            image.set(y, x, color);
        }
        else {
            image.set(x, y, color);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1 > y0 ? 1 : -1);
            error2 -= dx * 2;
        }
    }

}




int main(int argc, char** argv) {
        TGAImage image(100, 100, TGAImage::RGB);
        image.set(52, 41, red);
        image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
        image.write_tga_file("output1.tga");


        //Test building many of the same image
        for (int i = 0; i < 1000; i++) {
            TGAImage im2 = TGAImage(100, 100, TGAImage::RGB);
            line(30, 30, 40, 70, im2, red);
            line(30, 30, 70, 40, im2, yellow);
            line(70, 40, 40, 70, im2, blue);
            im2.flip_vertically();
            im2.write_tga_file("output2.tga");
        }




        return 0;
}