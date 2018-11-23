#include <iostream>
#include <graphics.h>
#include <stdarg.h>
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
void getAllPoints(int Count, ... )
{
   Point *P;
   va_list Numbers;
   va_start(Numbers, Count);
   int i;
   for(i=0; i<Count; i++)
   {
      P = va_arg(Numbers, Point*);
      cout<<"Enter Point "<<i+1<<":"<<endl;
      cout<<"Enter x:";
      cin>>P->x;
      cout<<"Enter y:";
      cin>>P->y;
   }
   va_end(Numbers);
}

int main()
{
   Point p1,p2,p3;
   getAllPoints(3,&p1,&p2,&p3);
   initwindow(1280,800,"",-3,-3);
   MyLine(p1,p2);
   MyLine(p2,p3);
   MyLine(p3,p1);
   getch();
   closegraph();
   return 0;
}
