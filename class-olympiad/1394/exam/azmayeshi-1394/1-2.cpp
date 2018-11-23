#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const long long maxn = (long long)1000 * 1000 * 1000;

long long bmm(long long a)
{
	long long b = 1;
	while(a % 2 == 0)
	{
		b *= 2;
		a /= 2;
	}
	return b;
}


int main()
{
	long long sum = 0;
	long long maxim = -1;
	for(long long a = 1; a <= maxn; a++)
	{
		long long c = bmm(a) * 2;
		long long b = a + c;
		if(a % 2 == 1)
			sum = (sum + ((maxn - b + 1) / c)) % 12841;
		else
		{
			sum = (sum + ((((maxn - c/2 + maxn % c) - a) / 2) / (c /2 ))) % 12841;
		}
		if(a > (long long)1000 * 1000 * 20)
		{
			cout << sum << endl;
	//		if(sum == maxim)
	//		{
	//			cout << maxim << endl;
	//			return 0;
	//		}
			maxim = sum;
		}
	}
	cout << sum % 12841 << endl;
}