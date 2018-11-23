#include <iostream>
#include <graphics.h>
using namespace std;
void mycircles(int x0,int y0,int m,int n,int k,int r)
{
   int i,j,x,y,t;
   for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	  {
		 x=x0+(2*j-1)*k*r+(j-1)*r;
		 y=y0+(2*i-1)*k*r+(i-1)*r;
		 for(t=1;t<=k;t++)
			circle(x,y,t*r);
      }
}
int main()
{
   int r,m,n,k,x,y;
   cout<<"Enter m,n,k:";
   cin>>m>>n>>k;
   cout<<"Enter r:";
   cin>>r;
   cout<<"Enter x,y:";
   cin>>x>>y;
   initwindow(1280,800,"",-3,-3);
   mycircles(x,y,m,n,k,r);
   getch();
   closegraph();
   return 0;
}
