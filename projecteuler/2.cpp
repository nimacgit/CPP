#include <iostream>

using namespace std;

int main()
{
	long long int a=1,b=2,c=3,sum=2;
	for(;c<=4000000;)
	{
		c=a+b;
		a=b;
		b=c;
		if(c%2==0)
		{
			sum+=c;
		}
	}
	cout<<sum;
}