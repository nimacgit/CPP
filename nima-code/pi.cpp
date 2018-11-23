#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int n=0,a=1;
	double sum=0;
	for(;n!=-1;)
	{
		sum=0.0;
		a=1;
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			sum+=1.00/(double(a*a));
			a++;
		}
		cout<<sqrt(sum)<<endl;
	}
}