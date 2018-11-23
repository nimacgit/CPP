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
void MyPolygon(Point p[], int n)
{
   int i;
   for(i=0;i<n-1;i++)
      MyLine(p[i],p[i+1]);
   MyLine(p[0],p[n-1]);
}
int main()
{
   int i,n;
   Point p[100];
   cout<<"Enter n:";
   cin>>n;
   for(i=0;i<n;i++)
   {
      cout<<"Enter Point "<<i+1<<":"<<endl;
      getPoint(p[i]);
   }
   initwindow(1280,800,"",-3,-3);
   MyPolygon(p,n);
   getch();
   closegraph();
   return 0;
}
