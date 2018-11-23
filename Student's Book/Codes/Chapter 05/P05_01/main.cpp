#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   initwindow(800,600);
   circle(300,300,100);
   putpixel(300,300,15);
   getch();
   closegraph();
   return 0;
}
