#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int a[1000];
	for(int i=0;i<1000;i++)
	{
		a[i]=s[i]-48;
	}
	long long int c=1,b=1;
	for(int i=0;i<1000-13;i++)
	{
		c=1;
		if(i==0)
		{
			for(int j=0;j<13;j++)
				b*=a[j];
		}
		else
		{
			for(int j=i;j<i+13;j++)
			{
				c*=a[j];
			}
		}
		if(c>b)
		{
			b=c;
			cout<<b<<endl;
		}

	}
	cout<<b;
}