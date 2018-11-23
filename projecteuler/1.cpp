#include <iostream>

using namespace std;

int main()
{
	int sum=0;
	int f=0;
	for(int i=1;i<1000;i++)
	{
		if(i%3==0)
		{
			f=1;
			sum+=i;
		}
		if(f!=1 && i%5==0)
		{
			sum+=i;
		}
		f=0;
	}
	cout<<sum;
}