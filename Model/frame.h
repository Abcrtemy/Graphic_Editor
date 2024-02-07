#ifndef FRAME_H
#define FRAME_H


class Frame
{
public:
    Frame(int x_1, int y_1, int x_2, int y_2);
    float x1, y1, x2, y2;
    float kx1, kx2, ky1, ky2;
};

#endif // FRAME_H
