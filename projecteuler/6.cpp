#include <iostream>

using namespace std;

int main()
{
	long long int a=0,b=0;
	for(int i=1;i<101;i++)
	{
		a+=i*i;
		b+=i;
	}
	b=b*b;
	cout<<b-a;
}