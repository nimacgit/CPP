#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int S=0,i,n;
   cout<<"Enter n:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
	  if((i%3==0)||(i%5==0))
		 S+=i;
   }
   cout<<"S="<<S;
   getch();
   return 0;
}
