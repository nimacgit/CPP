#include <iostream>
#include <conio.h>
#include <stdarg.h>
using namespace std;
double average( int Count, ... )
{
   va_list Numbers;
   va_start(Numbers, Count);
   int Sum = 0, i;
   for(i=0; i<Count; i++)
      Sum += va_arg(Numbers, int);
   va_end(Numbers);
   if(Count>0)
	   return (double(Sum)/Count);
   else
	   return 0;
}

int main()
{
   int a=1, b=2, c=7;
   cout<<"("<<a<<"+"<<b<<"+"<<c<<")/3="<<average(3,a,b,c);
   getch();
   return 0;
}
