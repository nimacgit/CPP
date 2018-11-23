#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const long long maxn = 2 * 1000 * 100 + 3;
long long n, a[maxn], sum;


long long findmin()
{
	for(int i = 0; i < n - 1; i++)
	{
		if(a[i] < a[i + 1])
		{
			sum+= a[i + 1];
		}
		else
		{
			sum+= a[i];
		}
	}
}

int main()
{
	scanf("%lli", &n);
	for(long long i = 0; i < n; i++)
		scanf("%lli", &a[i]);
	findmin();
	cout << sum << endl;


}