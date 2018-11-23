#include <iostream>
#include <conio.h>
using namespace std;
void f(int *x)
{
   *x=0;
}
int main()
{
   int a=10;
   cout<<"a="<<a<<endl;
   f(&a);
   cout<<"a="<<a<<endl;
   getch();
   return 0;
}
