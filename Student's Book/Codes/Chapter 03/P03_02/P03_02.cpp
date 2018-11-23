#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	double a,b,x;
	cout<<"Enter a,b to solve ax+b=0:";
	cin>>a>>b;
	x=-b/a;
	cout<<"x="<<x;
	getch();
	return 0;
}
