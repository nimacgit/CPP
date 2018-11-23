#include <iostream>
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
void fractal(int n, Point P1, Point P2)
{
   if(n<=0)
   {
      bar(P1.x,P1.y,P2.x,P2.y);
   }
   else
   {
      Point Q1,Q2;
      Q1.x=P1.x;
      Q1.y=P1.y;
      Q2.x=(2*P1.x+P2.x)/3;
      Q2.y=(2*P1.y+P2.y)/3;
      fractal(n-1,Q1,Q2);
      Q1.x=(P1.x+2*P2.x)/3;
      Q1.y=P1.y;
      Q2.x=P2.x;
      Q2.y=(2*P1.y+P2.y)/3;
      fractal(n-1,Q1,Q2);
      Q1.x=(2*P1.x+P2.x)/3;
      Q1.y=(2*P1.y+P2.y)/3;
      Q2.x=(P1.x+2*P2.x)/3;
      Q2.y=(P1.y+2*P2.y)/3;
      fractal(n-1,Q1,Q2);
      Q1.x=P1.x;
      Q1.y=(P1.y+2*P2.y)/3;
      Q2.x=(2*P1.x+P2.x)/3;
      Q2.y=P2.y;
      fractal(n-1,Q1,Q2);
      Q1.x=(P1.x+2*P2.x)/3;
      Q1.y=(P1.y+2*P2.y)/3;
      Q2.x=P2.x;
      Q2.y=P2.y;
      fractal(n-1,Q1,Q2);
   }
}

int main()
{
   int n;
   Point p1,p2;
   cout<<"Enter n:";
   cin>>n;
   cout<<"Enter Point 1:"<<endl;
   getPoint(p1);
   cout<<"Enter Point 2:"<<endl;
   getPoint(p2);
   initwindow(1280,800,"",-3,-3);
   setfillstyle(1,15);
   fractal(n,p1,p2);
   getch();
   closegraph();
   return 0;
}
