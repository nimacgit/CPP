#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   int x[100],y[100],n,i;
   cout<<"Enter n:";
   cin>>n;
   for(i=0;i<n;i++)
   {
      cout<<"Enter x["<<i+1<<"]:";
      cin>>x[i];
      cout<<"Enter y["<<i+1<<"]:";
      cin>>y[i];
   }
   initwindow(1280,800,"",-3,-3);
   for(i=0;i<n-1;i++)
	  line(x[i],y[i],x[i+1],y[i+1]);
   line(x[0],y[0],x[n-1],y[n-1]);
   getch();
   closegraph();
   return 0;
}
