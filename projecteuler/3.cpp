#include <iostream>

using namespace std;

int main()
{
	long long int a=600851475143,b=2,c=2;
	for(;a>1;b++)
	{
		if(a%b==0)
		{
			c=b;
			for(;a%b==0;a/=b);
		}
	}
	cout<<c;
}