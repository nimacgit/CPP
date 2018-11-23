#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int i,n;
   double S=0,a=1;
   cout<<"Enter n:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
	  S+=a/(2*i-1);
	  a=-a;
   }
   S=4*S;
   cout<<"Pi="<<S;
   getch();
   return 0;
}
