#include<iostream>
#include<conio.h>
using namespace std;
unsigned fact(unsigned n)
{
   unsigned r=1,i;
   for(i=2;i<=n;i++)
      r*=i;
   return r;
}
int main()
{
   int n;
   cout<<"Enter n:";
   cin>>n;
   cout<<n<<"!="<<fact(n);
   getch();
   return 0;
}
