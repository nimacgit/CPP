#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
   unsigned n,i,j,p;
   cout<<"Enter n:";
   cin>>n;
   for(i=2;i<=n;i++)
   {
	  p=1;
	  for(j=2;j<=sqrt(i);j++)
	     if(i%j==0)
		    p=0;
	  if(p==1)
		 cout<<i<<" is prime"<<endl;
   }
   getch();
   return 0;
}
