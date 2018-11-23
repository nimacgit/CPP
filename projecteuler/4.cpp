#include <iostream>

using namespace std;


int main()
{
	long long int a=100, b=100,c=0;
	for(;b<1000;b++)
	{
		for(a=100;a<1000;a++)
		{
			for(int num=a*b,nump=0;num>0;num/=10)
			{
				nump=nump*10+num%10;
				if(a*b==nump)
				{
					if(nump>c)
						c=nump;
				}
			}
			
		}

	}
	cout<<c;

}