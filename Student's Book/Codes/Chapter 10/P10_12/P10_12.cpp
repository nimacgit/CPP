#include <iostream>
#include <conio.h>
using namespace std;
unsigned fib(unsigned n)
{
   if(n>2)
      return fib(n-1)+fib(n-2);
   else
      return 1;
}
int main()
{
   int n;
   cout<<"Enter n:";
   cin>>n;
   cout<<"fib("<<n<<")="<<fib(n);
   getch();
   return 0;
}
