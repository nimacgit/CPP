#include<iostream>
#include<conio.h>
using namespace std;
int f(int x)
{
   x=0;
   return x;
}
int main()
{
   int i=10,j;
   j=f(i);
   cout<<"i="<<i<<" ,j="<<j;
   getch();
   return 0;
}
