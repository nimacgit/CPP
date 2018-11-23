#include <iostream>
#include <math.h>
using namespace std;

int z(int a)
{
	int f=1;
	for(int i=a;i>0;i/=10)
	{
		if((i%10)%2==0 || (i%10)%5 ==0)
		{
			f=0;
			i=0;
		}
	}
	return(f);
}

int p(int a)
{
	int f=1;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			f=0;
			i=a;
		}
	}
	return(f);
}

int main()
{
	int k=0;
	for(int i=2;i<1000000;i++)
	{
		if(p(i)==1)
			if(z(i)==1)
				k++;
	}
	cout<<k<<endl;
}