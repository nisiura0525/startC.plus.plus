#include "TAKO.h"
#include "libOne.h"
void TAKO::init() { //4
    Px = random() % (int)width;
    Py = random() % (int)height;
    Angle = 0;
}
void TAKO::setImage(int img) {
    Img = img;
}
void TAKO::draw() {
    image(Img, Px, Py, Angle);
}
void TAKO::move() {
    Angle += 0.01f;
}