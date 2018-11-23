#include<iostream>
#include <graphics.h>
using namespace std;
struct Point
{
   int x;
   int y;
};
void getPoint(Point &p)
{
   cout<<"Enter x:";
   cin>>p.x;
   cout<<"Enter y:";
   cin>>p.y;
}
void MyLine(Point p1, Point p2)
{
   line(p1.x, p1.y, p2.x, p2.y);
}
int main()
{
   Point p1, p2;
   cout<<"Enter Point 1:"<<endl;
   getPoint(p1);
   cout<<"Enter Point 2:"<<endl;
   getPoint(p2);
   initwindow(1280,800,"",-3,-3);
   MyLine(p1,p2);
   getch();
   closegraph();
   return 0;
}
