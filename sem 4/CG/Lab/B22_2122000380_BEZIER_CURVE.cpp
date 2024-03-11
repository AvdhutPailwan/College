#include<graphics.h>
#include<iostream>
#include<math.h>

using namespace std;

/*
sample input :

10 10
100 200
300 200
250 10
*/
void axisXY(int x, int y)
{
    line(0, y/2, x, y/2);
    line(x/2, 0, x/2, y);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmax = getmaxx();   // get maximum length of X-axis
    int ymax = getmaxy();   // get maximum length of Y-axis
    int ox = xmax/2, oy = ymax/2;

    axisXY(xmax, ymax);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    float x, y;

    cout<<"control point #1 (x, y) = ";
    cin>>x1>>y1;

    cout<<"control point #2 (x, y) = ";
    cin>>x2>>y2;

    cout<<"control point #3 (x, y) = ";
    cin>>x3>>y3;

    cout<<"control point #4 (x, y) = ";
    cin>>x4>>y4;

    setcolor(2);
    line(x1 + ox, oy - y1, ox + x2, oy - y2);
    line(ox + x2, oy - y2, ox + x3, oy - y3);
    line(ox + x3, oy - y3, ox + x4, oy - y4);

    setcolor(3);
    for(float t = 0.000; t<1.000; t+=0.001)
    {
        x = ( float(x1) * pow(1-t, 3) ) + ( float(x2) * 3 * t * pow(1-t, 2) ) + ( float(x3) * 3 * pow(t, 2) * (1-t) ) + ( float(x4) * pow(t, 3) );
        y = ( float(y1) * pow(1-t, 3) ) + ( float(y2) * 3 * t * pow(1-t, 2) ) + ( float(y3) * 3 * pow(t, 2) * (1-t) ) + ( float(y4) * pow(t, 3) );
        putpixel((float)ox + x, (float)oy - y, 3);
    }



    getch();
    closegraph();
    return 0;
}
