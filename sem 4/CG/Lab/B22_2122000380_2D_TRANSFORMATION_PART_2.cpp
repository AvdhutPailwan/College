#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tx, ty;
    float sx, sy;


    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    int xmax = getmaxx();   // get maximum length of X-axis
    int ymax = getmaxy();   // get maximum length of Y-axis

    line(xmax/2, 0, xmax/2, ymax);  // Y-axis
    line(0, ymax/2, xmax, ymax/2);  // X-axis


    cout<<"X-axis ranges from "<<-xmax/2<<" to "<<xmax/2<<endl<<endl; // X-axis limits
    cout<<"Y-axis ranges from "<<-ymax/2<<" to "<<ymax/2<<endl<<endl; // Y-axis limits





    int x1, y1, x2, y2, x3, y3, x4, y4;
    cout<<"Enter the (x,y) coordinates of the rectangle :\n top-right : ";
    cin>>x1>>y1;
    cout<<" top-left : ";
    cin>>x2>>y2;
    cout<<" bottom-left : ";
    cin>>x3>>y3;
    cout<<" bottom-right : ";
    cin>>x4>>y4;


    x1 = xmax/2 + x1, x2 = xmax/2 + x2, x3 = xmax/2 + x3, x4 = xmax/2 + x4;
    y1 = ymax/2 - y1, y2 = ymax/2 - y2, y3 = ymax/2 - y3, y4 = ymax/2 - y4;


    setcolor(1);
    line(x1,y1,x2,y2);  //rectangle with respect to origin
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x1,y1);

    int i = 1;

    bool flag = true;

    while(flag)
    {

        int op; /// operation to perform
        cout<<"Enter the operation\n1. Translation\n2. Scaling\n3. Rotation\n4. exit"<<endl;
        cin>>op;

        switch(op)
        {
        case 1:
            cout<<"Enter the value of tx and ty for translation :"<<endl;
            cin>>tx>>ty;

            x1 = tx + x1, x2 = tx + x2, x3 = tx + x3, x4 = tx + x4;
            y1 = -ty + y1, y2 = -ty + y2, y3 = -ty + y3, y4 = -ty + y4;


            cleardevice();  // clear previous output

            setcolor(15);   // color white

            // X and Y axis
            line(xmax/2, 0, xmax/2, ymax);
            line(0, ymax/2, xmax, ymax/2);

            setcolor(i%15 + 1); // set color for rectangle
            i++;

            line(x1,y1,x2,y2);  //rectangle with respect to origin
            line(x2,y2,x3,y3);
            line(x3,y3,x4,y4);
            line(x4,y4,x1,y1);
            break;
        case 2:
            cout<<"Enter the value of sx and sy for scaling :"<<endl;
            cin>>sx>>sy;   // scaling factors

            // calculate vertex point (x,y) after scaling

            x1 = ((x1 - xmax/2) * sx) + xmax/2;
            x2 = ((x2 - xmax/2) * sx) + xmax/2;
            x3 = ((x3 - xmax/2) * sx) + xmax/2;
            x4 = ((x4 - xmax/2) * sx) + xmax/2;
            y1 = ((y1 - ymax/2) * sy) + ymax/2;
            y2 = ((y2 - ymax/2) * sy) + ymax/2;
            y3 = ((y3 - ymax/2) * sy) + ymax/2;
            y4 = ((y4 - ymax/2) * sy) + ymax/2;


            /// draw rectangle after scaling

            cleardevice();  // clear previous output

            setcolor(15);   // color white

            // X and Y axis
            line(xmax/2, 0, xmax/2, ymax);
            line(0, ymax/2, xmax, ymax/2);


            setcolor(i%15 + 1);     // set color for rectangle
            i++;


            line(x1,y1,x2,y2);  //rectangle with respect to origin
            line(x2,y2,x3,y3);
            line(x3,y3,x4,y4);
            line(x4,y4,x1,y1);
            break;
        case 3:
            double angle, s, c;
            cout<<"enter the angle : "<<endl;
            cin>>angle;


            c = cos(angle * M_PI/180); // cos of the given angle
            s = sin(angle * M_PI/180); // sin of the given angle

            int tempx;


            // calculate vertex (x,y) after rotation
            tempx = x1;
            x1 = floor( (x1 - xmax/2) * c + (y1 - ymax/2) * s + xmax/2);
            y1 = floor(-(tempx - xmax/2) * s + (y1 - ymax/2) * c + ymax/2);
            tempx = x2;
            x2 = floor( (x2 - xmax/2) * c + (y2 - ymax/2) * s + xmax/2);
            y2 = floor(-(tempx - xmax/2) * s + (y2 - ymax/2) * c + ymax/2);
            tempx = x3;
            x3 = floor( (x3 - xmax/2) * c + (y3 - ymax/2) * s + xmax/2);
            y3 = floor(-(tempx - xmax/2) * s + (y3 - ymax/2) * c + ymax/2);
            tempx = x4;
            x4 = floor( (x4 - xmax/2) * c + (y4 - ymax/2) * s + xmax/2);
            y4 = floor(-(tempx - xmax/2) * s + (y4 - ymax/2) * c + ymax/2);


            /// draw rotated rectangle

            cleardevice();  // clear previous output

            setcolor(15);   // color white

            // X and Y axis
            line(xmax/2, 0, xmax/2, ymax);
            line(0, ymax/2, xmax, ymax/2);


            setcolor(i%15 + 1);     // set color for rectangle
            i++;


            line(x1,y1,x2,y2);  //rectangle with respect to origin
            line(x2,y2,x3,y3);
            line(x3,y3,x4,y4);
            line(x4,y4,x1,y1);

            break;
        case 4:
            flag = false;
            break;
        }
    }

    getch();
    closegraph();
    return 0;
}
