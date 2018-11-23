#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   int x,y,r,n,i;
   cout<<"Enter n:";
   cin>>n;
   cout<<"Enter r:";
   cin>>r;
   initwindow(1280,800,"",-3,-3);
   x=getmaxx()/2;
   y=getmaxy()/2;
   for(i=1;i<=n;i++)
	  circle(x,y,i*r);
   getch();
   closegraph();
   return 0;
}
