#include "WavefrontVisualizer.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
int main()
{
    Mat image(800 , 800, CV_8UC3, Scalar(0,0,0));
    Model model = Model("D:/resources/NaUKMA/obj/african_head.obj");
    /*line(13, 20, 80, 40, &image, white);
    line(20, 13, 40, 80, &image, red);
    line(80, 40, 13, 20, &image, red);*/
    
    DrawModel(&image , &model);
    namedWindow("Display window");
    imshow("Display window", image);
    waitKey(0);
    return 0;
}

