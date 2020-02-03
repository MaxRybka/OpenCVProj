#include "YCbCrConvert.h"
//#define N_DEBUG;

///<summary>
///Method for converting image data from RGB color system to YCbCr 
///</summary>
/// <param name="image">Used to indicate status.</param>
void Convert(Mat* image)
{
#ifndef N_DEBUG
	cout << "Input image size : "<<image->size<<endl;
#endif
    Vec3b vec;
	uchar Y, Cb, Cr;
    float R, G, B;

    for (int i = 0; i < image->rows; i++) {
        for (int j = 0; j < image->cols; j++) {
            
            vec = image->at<Vec3b>(i,j);
           
            B = vec[0];
            G = vec[1];
            R = vec[2];

            Y = (int)(0.299 * R + 0.587 * G + 0.114 * B);
            Cb = (int)(-0.169 * R - 0.331 * G + 0.500 * B) + DELTA;
            Cr = (int)(0.500 * R - 0.418 * G - 0.082 * B) + DELTA;

            vec[2] = Y;
            vec[1] = Cb;
            vec[0] = Cr;

            image->at<Vec3b>(i, j) = vec;
        }
    }

}
