#include<iostream>
#include<graphics.h>
using namespace std;

class ThreeD
{
private:
    int maxX, maxY, rtangl[4][4];

public:
    ThreeD(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4)
    {
        maxX = getmaxx();
        maxY = getmaxy();
        rtangl = {
            {x1, y1, z1, 1},
            {x2, y2, z2, 1},
            {x3, y3, z3, 1},
            {x4, y4, z4, 1}
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    getch();
    closegraph();
    return 0;
}
