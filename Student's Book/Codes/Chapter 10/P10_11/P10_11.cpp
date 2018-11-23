#include <iostream>
#include <conio.h>
using namespace std;
unsigned fact(unsigned n)
{
   if(n>1)
      return n*fact(n-1);
   else
      return 1;
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
