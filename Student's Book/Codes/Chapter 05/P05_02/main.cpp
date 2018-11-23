#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   int x1,y1,x2,y2,xm,ym;
   cout<<"Enter x1,y1,x2,y2:";
   cin>>x1>>y1>>x2>>y2;
   initwindow(1280,800,"",-3,-3);
   line(x1,y1,x2,y2);
   xm=(x1+x2)/2;
   ym=(y1+y2)/2;
   circle(xm,ym,5);
   getch();
   closegraph();
   return 0;
}
