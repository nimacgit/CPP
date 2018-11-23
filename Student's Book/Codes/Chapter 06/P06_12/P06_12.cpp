#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   unsigned n,i,j,p;
   cout<<"Enter n:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=i;j++)
         cout<<"*";
      cout<<endl;
   }
   getch();
   return 0;
}
