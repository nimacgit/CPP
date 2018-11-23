#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
   unsigned n,i,p=1;
   cout<<"Enter n:";
   cin>>n;
   for(i=2;i<=sqrt(n);i++)
   {
	  if(n%i==0)
		 p=0;
   }
   if(p==1)
	  cout<<n<<" is prime";
   else
	  cout<<n<<" is not prime";
   getch();
   return 0;
}
