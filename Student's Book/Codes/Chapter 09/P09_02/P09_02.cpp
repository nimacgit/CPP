#include<iostream>
#include<conio.h>
using namespace std;
int zarb(int x, int y)
{
   return x*y;
}
int main()
{
   int i,j;
   cout<<"Enter two numbers:";
   cin>>i>>j;
   cout<<i<<"*"<<j<<"="<<zarb(i,j);
   getch();
   return 0;
}
