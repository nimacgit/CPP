#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int S=0,a,i,n;
   cout<<"Enter n:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
	  cout<<"Enter number #"<<i<<":";
	  cin>>a;
	  S=S+a;
   }
   cout<<"Average is: "<<double(S)/n;
   getch();
   return 0;
}
