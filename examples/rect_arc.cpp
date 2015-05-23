#include "../twombly.hpp"

using namespace tw;

int main(int argc, char *argv[]){
    Mat3b im(400, 400);

    auto ctx = DrawingRGB24(im);

    ctx.newPath();
    ctx.setColor(0, 0, 255);
    ctx.rect(10, 20, 210, 120);
    ctx.fill();

    ctx.newPath();
    ctx.setColor(200, 0, 255);
    ctx.lineWidth(10);
    ctx.moveTo(50, 50);
    ctx.arcTo(70, 50, 10, 10, 0.3);
    ctx.stroke();

    imwrite("rect_arc.tiff", im);
    return 0;
}
