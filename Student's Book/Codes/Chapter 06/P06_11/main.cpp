#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   int x,y,r,m,n,k,i,j,t;
   cout<<"Enter m,n,k:";
   cin>>m>>n>>k;
   cout<<"Enter r:";
   cin>>r;
   initwindow(1280,800,"",-3,-3);
   for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	  {
		 x=(2*j-1)*k*r+(j-1)*r;
		 y=(2*i-1)*k*r+(i-1)*r;
		 for(t=1;t<=k;t++)
			circle(x,y,t*r);
      }
   getch();
   closegraph();
   return 0;
}
