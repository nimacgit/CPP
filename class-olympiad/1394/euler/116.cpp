#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;



const long long maxn = 1000;
long long d[maxn + 10];

long long ways(long long m, long long n)
{
	for(long long i = 0; i < m; i++)
		d[i] = 1;
	d[m] = 2;
	for(long long i = m + 1; i <= n; i++)
	{
		d[i] = 0;
		d[i] += d[i - 1];
		d[i] += d[i - m];
	}
	return d[n];
}


int main()
{
	cout << ways(3,50) + ways(4, 50) + ways(2, 50) - 3 << endl;
}