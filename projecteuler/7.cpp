#include <iostream>

using namespace std;

int main()
{
	long long int a=2,isp=0,p=0,s=1;
	for(;p<=10001;a++)
	{
		isp=1;
		for(int i=2;i<=a/2;i++)
		{
			if(a%i==0)
			{
				isp=0;
				break;
			}
		}
		if(isp==1)
		{
			p++;
			if(p>9998)
				cout<<" "<<p<<"  "<<a<<endl;
		}
	}
	cout<<a;
}