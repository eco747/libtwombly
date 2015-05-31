#ifndef TWOMBLY_IMAGE_HEADER
#define TWOMBLY_IMAGE_HEADER
#include <bitset>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>

#ifndef NO_OPENCV
#include <opencv2/opencv.hpp>
#endif

namespace tw {

using namespace cv;

typedef float Pixel __attribute__ ((vector_size (16)));

#ifndef NO_OPENCV
// simple content based hash
std::bitset<64> hash(Mat const &im);
#else
class Point {
    double x, y;
};
class Rectangle {
    double x, y, width, height;
};
#endif

} //namespace tw

#endif //TWOMBLY_IMAGE_HEADER
