#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
   double a,b,c,x1,x2,D;
   cout<<"Enter a,b,c to solve ax^2+bx+c=0 :";
   cin>>a>>b>>c;
   D=b*b-4*a*c;
   if(D>0)
   {
	  x1=(-b+sqrt(D))/(2*a);
	  x2=(-b-sqrt(D))/(2*a);
	  cout<<"Equation has two different answers:"<<endl;
	  cout<<"x1="<<x1<<", x2="<<x2<<endl;
   }
   else if(D==0)
   {
	  x1=(-b+sqrt(D))/(2*a);
	  cout<<"Equation has two repeated answers:"<<endl;
	  cout<<"x1=x2="<<x1<<endl;
   }
   else
   {
	  cout<<"Equation has no answer..."<<endl;
   }
   getch();
   return 0;
}
