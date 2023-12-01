#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // read the image file
    Mat image = imread("../images/manzanas.jpg", IMREAD_COLOR);

    // read each pixel (RGB pixel)
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Point3_<uchar>* p = image.ptr<Point3_<uchar>>(r, c);
            // x: B, y: G, z: R
            printf("(%d %d %d) ", p->x, p->y, p->z);
        }
    }

    return 0;
}

