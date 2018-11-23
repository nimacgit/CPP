#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
   unsigned i,j;
   for(i=1;i<=10;i++)
   {
	  for(j=1;j<=10;j++)
		 cout<<i*j<<"\t";
	  cout<<endl;
   }
   getch();
   return 0;
}
