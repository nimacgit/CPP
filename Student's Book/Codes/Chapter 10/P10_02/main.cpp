#include<iostream>
#include <graphics.h>
using namespace std;
struct Point
{
   int x;
   int y;
};

void MyLine(Point p1, Point p2)
{
   line(p1.x, p1.y, p2.x, p2.y);
}
int main()
{
   Point p1, p2;
   cout<<"Enter x1,y1:";
   cin>>p1.x>>p1.y;
   cout<<"Enter x2,y2:";
   cin>>p2.x>>p2.y;
   initwindow(1280,800,"",-3,-3);
   MyLine(p1,p2);
   getch();
   closegraph();
   return 0;
}
