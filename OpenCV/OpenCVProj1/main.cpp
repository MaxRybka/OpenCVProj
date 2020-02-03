#include "YCbCrConvert.h"
int main()
{
    Mat image;
    //image = imread("D:/NaUKMA/CompGraphics/ForVetroscope/rgb.png", IMREAD_COLOR);
    image = imread("D:/NaUKMA/CompGraphics/ForVetroscope/original.tif", IMREAD_COLOR);

    if (!image.data)
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    Convert(&image);
    namedWindow("Display window");
    imshow("Display window", image);

    waitKey(0);
    return 0;
}
