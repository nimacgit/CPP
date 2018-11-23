#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int *p,n,i,S=0;
   cout<<"Enter n:";
   cin>>n;
   p=new int[n];
   for(i=0;i<n;i++)
   {
      cout<<"Enter p"<<i+1<<":";
      cin>>p[i];
   }
   for(i=0;i<10;i++)
      S+=p[i];
   cout<<"Sum="<<S;
   delete[] p;
   getch();
   return 0;
}
