#include<graphics.h>
#include<iostream>
#include<string>

using namespace std;

/*

sample input :-

100 100
300 100
-10 5
-10 480
-10 -10
700 500
-10 -10
600 400

*/


void CohenSutherlandLineClippingAlgorithm(int x1, int y1, int x2, int y2)
{
    const int maxx = getmaxx(), maxy = getmaxy();
    /// T(0) B(1) R(2) L(3)
    char region1[5], region2[5], andResult[5];

    region2[4]=region1[4]=andResult[4]='\0';
    line(x1, y1, x2, y2);

    if(y1 < 0)
        region1[0] = '1', region1[1] = '0';
    else if(y1>maxy)
        region1[0] = '0', region1[1] = '1';
    else
        region1[0] = '0', region1[1] = '0';

    if(y2 < 0)
        region2[0] = '1', region2[1] = '0';
    else if(y2>maxy)
        region2[0] = '0', region2[1] = '1';
    else
        region2[0] = '0', region2[1] = '0';

    if(x1 < 0)
        region1[3] = '1', region1[2] = '0';
    else if(x1>maxx)
        region1[3] = '0', region1[2] = '1';
    else
        region1[3] = '0', region1[2] = '0';

    if(x2 < 0)
        region2[3] = '1', region2[2] = '0';
    else if(x2>maxx)
        region2[3] = '0', region2[2] = '1';
    else
        region2[3] = '0', region2[2] = '0';



    for(int i = 0; i<4; i++)
    {
        if(region1[i]== '1' && region2[i] == '1')
            andResult[i] = '1';
        else
            andResult[i] = '0';
    }

    bool cv = false, pv = false, iv = false; // cv --> completely visible, pv --> partially visible, iv --> invisible

    if(strcmp(andResult, "0000"))
        iv = true;
    else
        if(!strcmp(region1, region2))
            cv = true;
        else
            pv = true;

    cout<<"region code :\n\t1st point : "<<region1<<"\n\t2nd point : "<<region2<<endl<<(cv? "\tcompletely visible\n\n":"")<<(pv? "\tpartially visible\n\n":"")<<(iv? "\tcompletely invisible\n\n":"");
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    cout<<"x is from 0 to "<<getmaxx()<<endl<<"y is from 0 to "<<getmaxy()<<endl<<endl;

    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8;

    cout<<"Line 1 :\n";
    cout<<"\tP1 = ";
    cin>>x1>>y1;
    cout<<"\tP2 = ";
    cin>>x2>>y2;

    cout<<"Line 2 :\n";
    cout<<"\tP3 = ";
    cin>>x3>>y3;
    cout<<"\tP4 = ";
    cin>>x4>>y4;

    cout<<"Line 3 :\n";
    cout<<"\tP5 = ";
    cin>>x5>>y5;
    cout<<"\tP6 = ";
    cin>>x6>>y6;

    cout<<"Line 4 :\n";
    cout<<"\tP7 = ";
    cin>>x7>>y7;
    cout<<"\tP8 = ";
    cin>>x8>>y8;

    cout<<endl<<endl;

    cout<<"Line 1 :\n";
    CohenSutherlandLineClippingAlgorithm(x1, y1, x2, y2);

    cout<<"Line 2 :\n";
    CohenSutherlandLineClippingAlgorithm(x3, y3, x4, y4);

    cout<<"Line 3 :\n";
    CohenSutherlandLineClippingAlgorithm(x5, y5, x6, y6);

    cout<<"Line 4 :\n";
    CohenSutherlandLineClippingAlgorithm(x7, y7, x8, y8);

    getch();
    closegraph();
    return 0;
}
