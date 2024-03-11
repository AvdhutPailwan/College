#include<iostream>
#include<graphics.h>

using namespace std;

void xyAxis(int x, int y)
{
    line(0, y/2, x, y/2);
    line(x/2, 0, x/2, y);
}

void mh(int &x, int &y, int &di)
{
    x++;
    di = di + (2 * x) + 1;
}

void md(int &x, int &y, int &di)
{
    x++;
    y--;
    di = di + (2 * x) - (2 * y) + 2;
}

void mv(int &x, int &y, int &di)
{
    y--;
    di = di - (2 * y) + 1;
}

void bresenhamCircle(int &ox, int &oy, int &x, int &y, int &di, int &limit)
{
    int delta;
    cout<<" setpixel\tdi\tdelta\tx\ty\n";
    cout<<"    -    \t"<<di<<"\t"<<"  -  \t"<<x<<"\t"<<y<<endl;
    while(y>=limit)
    {
        cout<<"  ("<<x<<","<<y<<")  \t";
        putpixel(ox+x, oy-y, CYAN), putpixel(ox-x, oy-y, CYAN), putpixel(ox-x, oy+y, CYAN), putpixel(ox+x, oy+y, CYAN); // 1st, 2nd, 3rd, 4th quadrant

        if(di<0)
        {
            delta = (2 * di) + (2 * y) - 1;
            if(delta <= 0)
                mh(x, y, di);
            else
                md(x, y, di);
        } else if(di>0)
        {
            delta = (2 * di) - (2 * x) - 1;
            if(delta <= 0)
                md(x, y, di);
            else
                mv(x, y, di);
        } else
            md(x, y, di);
        cout<<di<<"\t"<<"  "<<delta<<"  \t"<<x<<"\t"<<y<<endl;
    }
}



int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmax = getmaxx();
    int ymax = getmaxy();

    xyAxis(xmax, ymax);

    int ox = xmax/2, oy = ymax/2;

    int *radius = (int*)malloc(sizeof(int));
    cout<<"Enter the radius of the circle : ";
    cin>>*radius;

    int x = 0;
    int y = *radius;
    int di = 2 * (1 - *radius);
    int limit = 0;

    free(radius);
    bresenhamCircle(ox, oy, x,y,di,limit);

    getch();
    closegraph();
    return 0;
}
