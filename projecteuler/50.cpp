#include <iostream>
#include <math.h>
using namespace std;

int sum=0;
int maxi=0;
int n=2;

int av(int a)
{
	int f=1;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			i=a;
			f=0;
		}
	}
	return(f);
}

int main()
{
	for(;sum<=1000;n++)
	{
		if(av(n)==1)
		{
			sum+=n;
		}
		if(av(sum)==1)
		{
			maxi=sum;
		}
	}
	cout<<maxi<<endl;
}
