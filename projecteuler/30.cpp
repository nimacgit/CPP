#include <iostream>

using namespace std;

int main()
{
	long long int sum=0,a=0;
	for(long long int i=2;i<100000000;i++)
	{
		for(long long int l=i;l>0;l/=10)
		{
			sum+=(l%10)*(l%10)*(l%10)*(l%10)*(l%10);
		}
		if(sum==i)
		{
			a+=sum;
			cout<<sum<<endl;
		}
		else
			sum=0;
	}
	cout<<a<<endl;
}