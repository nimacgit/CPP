#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int a[200002];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=0;
	for(int i=n;i>0;i--)
	{
		if(a[i]>=i)
		{
			for(int j=0;j<i;j++)
				a[j]+=a[i]/i;
		}
	}
	printf("%d",a[0]);
	printf("\n");
}
