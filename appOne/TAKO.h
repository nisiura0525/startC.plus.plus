#pragma once
class TAKO//3
{
private:
    float Px, Py, Angle;
    int Img = 0;
public:
    void init();
    void setImage(int img);
    void draw();
    void move();
};

