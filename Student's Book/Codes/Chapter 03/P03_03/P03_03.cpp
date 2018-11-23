#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int a,b,c,m;
	cout<<"Enter a,b,c:";
	cin>>a>>b>>c;
	m=(a+b+c)*(a+b+c);
	cout<<"("<<a<<"+"<<b<<"+"<<c<<")^2="<<m;
	getch();
	return 0;
}
