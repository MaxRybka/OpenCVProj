#pragma once
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;

class Color {
public:
	Color(unsigned int r, unsigned int g, unsigned int b) {
		R = r;
		G = g;
		B = b;
	}
	unsigned int R;
	unsigned int G;
	unsigned int B;
};

const Color white = Color(255, 255, 255);
const Color red = Color(255, 0, 0);

void line(int x0, int y0, int x1, int y1, cv::Mat* image, Color color);

