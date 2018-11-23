#include <iostream>
#include <string>
using namespace std;

long long int n;
long long int a[100000];
int t;

void get()
{
	cin>>n;
	cin>>t;
	for(long long int i=1;i<n;i++)
	{
		cin>>a[i];
	}
}
 
int main()
{
	get();
	int f=0;
	for(int k=1;k<=t;)
	{
		if(k==t)
		{
			cout<<"YES"<<endl;
			f=1;
		}
		k=a[k]+k;
	}
	if(f!=1)
		cout<<"NO"<<endl;

}
