#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int x;
   cout<<"Enter a number:";
   cin>>x;
   if(x<0)
	  cout<<"Negative";
   else if(x>0)
	  cout<<"Positive";
   else
	  cout<<"Zero";
   getch();
   return 0;
}
