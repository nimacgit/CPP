#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	vector<int> v;
	long long int n;
	long long int a=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a*=70;
	}
	time_t t1,t2;
	t1=clock ();
	for(long long int i=0;i<a;i++)
	{
		v.push_back(i);
	}
	t2=clock();
	cout<<t2-t1<<endl<<double((t2-t1)/1000000.0)<<endl;

}
