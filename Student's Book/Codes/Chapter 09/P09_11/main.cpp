#include <iostream>
#include <graphics.h>
#include <nodet.h>
using namespace std;
void draw_path(int x,int y,int k,string path)
{
   int i;
   moveto(x,y);
   for(i=0;i<path.length();i++)
      switch(chartolower(path[i]))
      {
         case 'u':
            linerel(0,-k);
         break;
         case 'd':
            linerel(0,k);
         break;
         case 'r':
            linerel(k,0);
         break;
         case 'l':
            linerel(-k,0);
         break;
      }
}
int main()
{
   int x,y,k;
   string s;
   cout<<"Enter a path by (U,D,R,L) characters:";
   cin>>s;
   cout<<"Now enter begining (x,y):";
   cin>>x>>y;
   cout<<"Now enter step size:";
   cin>>k;
   initwindow(1280,800,"",-3,-3);
   draw_path(x,y,k,s);
   getch();
   closegraph();
   return 0;
}
