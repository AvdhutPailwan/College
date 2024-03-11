#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    getch();
    closegraph();
    return 0;
}
