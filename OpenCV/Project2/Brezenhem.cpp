#include "Brezenhem.h"

using namespace cv;

void line(int x0, int y0, int x1, int y1, Mat* image,Color color) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
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
    float derror = std::abs(dy / float(dx));
    float error = 0;
    int y = y0;
    cv::Vec3b vec;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            vec = image->at<Vec3b>(y, x);

            vec[0] = (uchar)color.B;
            vec[1] = (uchar)color.G;
            vec[2] = (uchar)color.R;

            image->at<Vec3b>(y, x) = vec;
        }
        else {
            vec = image->at<Vec3b>(x, y);

            //vec[0] = (uchar)color.B;
            //vec[1] = (uchar)color.G;
            //vec[2] = (uchar)color.R;

            //image->at<Vec3b>(x, y) = vec;
        }
        error += derror;

        if (error > .5) {
            y += (y1 > y0 ? 1 : -1);
            error -= 1.;
        }
    }
}