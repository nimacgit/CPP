#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long int sum=0;
	int f=1;
	for(long long int i=2;i<2000000;i++)
	{
		for(int k=2;k<=sqrt(i);k++)
			if(i%k==0)
			{
				f=0;
				k=i/2;
			}
		if(f==1)
		{
			sum+=i;
		}
		else
			f=1;
	}
	cout<<sum<<endl;
}