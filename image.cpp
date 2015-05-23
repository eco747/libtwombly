#include "image.hpp"

namespace tw {

std::bitset<64> hash(Mat &&im){
    std::bitset<64> h = 0;

    Mat sized(8, 8, im.depth()), gray;

    switch(im.channels()){
    case 1:
        gray = im; break;
    case 3:
        cvtColor(im, gray, COLOR_BGR2GRAY); break;
    case 4:
        cvtColor(im, gray, COLOR_BGRA2GRAY); break;
    }
    resize(gray, sized, sized.size());

    float avg = 0;
    for(size_t i = 0; i < sized.total(); i++){
        avg += sized.data[i];
    }
    avg /= 64;

    size_t bitno = 0;
    for(size_t i = 0; i < sized.total(); i++){
        h.set(bitno, i > avg);
        bitno++;
    }

    return h;
}

}; // namespace tw
