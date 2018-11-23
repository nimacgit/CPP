#include <iostream>

using namespace std;

int main()
{
	long long int a=10,is=0,f=1;
	for(;f!=0;a++)
	{
		is=1;
		for(int i=2;i<20;i++)
		{
			if(a%i!=0)
			{
				is=0;
				break;
			}
		}
		if(is==1)
			f=0;
	}
	cout<<a;
}