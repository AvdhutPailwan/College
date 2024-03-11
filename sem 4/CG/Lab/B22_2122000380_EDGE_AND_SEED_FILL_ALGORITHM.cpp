#include<graphics.h>
#include<iostream>

using namespace std;

// template for seed fill and edge fill
class FillAlgo
{
protected:
    int xmax = getmaxx();   // get maximum length of X-axis
    int ymax = getmaxy();   // get maximum length of Y-axis
    int ox = xmax/2, oy = ymax/2;
    int fillColor = YELLOW, edgeColor = WHITE, oldColor = BLACK;

    void axisXY()
    {
        setcolor(CYAN);
        line(xmax/2, 0, xmax/2, ymax);  // Y-axis
        line(0, ymax/2, xmax, ymax/2);  // X-axis
    }

    void rect(int x1, int y1, int x2, int y2)
    {
        setcolor(edgeColor);
        line(x1,y1,x1,y2);
        line(x2,y1,x2,y2);
        line(x1,y1,x2,y1);
        line(x1,y2,x2,y2);
    }

    virtual void algorithm(int x, int y){} // algorithm for 8 connected
public:
    virtual void implement(int x1, int y1, int x2, int y2){}
};

class SeedFill : public FillAlgo
{
protected:
    void algorithm(int x, int y)
    {
        int c = getpixel(x, y);

        if(c == oldColor)
        {
            putpixel(x, y, fillColor);

            algorithm(x, y-1);
            algorithm(x, y+1);
            algorithm(x+1, y);
            algorithm(x+1, y-1);
            algorithm(x+1, y+1);
            algorithm(x-1, y);
            algorithm(x-1, y-1);
            algorithm(x-1, y+1);
        }
    }

public:
    void implement(int x1, int y1, int x2, int y2)
    {
        cleardevice();
        axisXY();

        x1 += ox, x2 += ox, y1 = oy - y1, y2 = oy - y2;

        rect(x1, y1, x2, y2);

        delay(2000);

        algorithm((x1+x2)/2, (y1+y2)/2);
    }
};

class EdgeFill : public FillAlgo
{
protected:
    void algorithm(int x, int y)
    {
        int c = getpixel(x, y);

        if(c != edgeColor && c != fillColor)
        {
            putpixel(x, y, fillColor);

            algorithm(x, y-1);
            algorithm(x, y+1);
            algorithm(x+1, y);
            algorithm(x+1, y-1);
            algorithm(x+1, y+1);
            algorithm(x-1, y);
            algorithm(x-1, y-1);
            algorithm(x-1, y+1);
        }
    }
public:
    EdgeFill()
    {
        cleardevice();
        axisXY();
    }

    void implement(int x1, int y1, int x2, int y2)
    {
        cleardevice();
        axisXY();

        x1 += ox, x2 += ox, y1 = oy - y1, y2 = oy - y2;

        rect(x1, y1, x2, y2);

        delay(2000);

        algorithm((x1+x2)/2, (y1+y2)/2);
    }
};

int main()
{
    int gd = DETECT, gm, choice;
    bool flag = true;

    initgraph(&gd, &gm, "");

    SeedFill *objSeed;
    EdgeFill *objEdge = new EdgeFill();
    delete(objEdge);

    int x1, y1, x2, y2;
    cout<<"(left, top) = ";
    cin>>x1>>y1;
    cout<<"(right, bottom) = ";
    cin>>x2>>y2;

    while(flag){
        cout<<"1. Edge Fill\t2. Seed Fill\t3. Exit :\t";
        cin>>choice;

        switch(choice)
        {
        case 1:
            objEdge = new EdgeFill();
            objEdge->implement(x1, y1, x2, y2);
            delete(objEdge);
            break;
        case 2:
            objSeed = new SeedFill();
            objSeed->implement(x1, y1, x2, y2);
            delete(objSeed);
            break;
        case 3:
            flag = false;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;
        }
    }

    getch();
    closegraph();
    return 0;
}
