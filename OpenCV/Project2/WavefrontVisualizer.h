#pragma once
#include <iostream>
#include "Model.h"
#include "Brezenhem.h"

void DrawModel(cv::Mat* image , Model* model) {
	for (int i=0; i<model->nfaces(); i++) {
        std::vector<int> face = model->face(i);
        for (int j=0; j<3; j++) {
            Vec3f v0 = model->vert(face[j]);
            Vec3f v1 = model->vert(face[(j+1)%3]);
            int x0 = (v0.x + 1.)* image->rows/2.;
            int y0 = (v0.y + 1.)* image->cols /2.;
            int x1 = (v1.x + 1.)* image->rows /2.;
            int y1 = (v1.y + 1.)* image->cols /2.;
            cout << "Line : " << x0 << " , " << y0 << " , " << x1 << " , " << y1 << endl;
            line(x0, y0, x1, y1, image, white);
        }
    }
}