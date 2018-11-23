#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main()
{
	cin>>n;
	int a[n][n];
	int p[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<n;j++)
		{
			a[j][i]=s[j]-48;
		}
	}
	for(int k=0;k<n;k++)
	{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i]>p[j])
			{
				if(a[i][j]==1)
					swap(p[i],p[j]);
			}

		}
	}
	}
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
}
