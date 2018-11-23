#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000;
long long d[maxn + 10];





int main()
{
	long long co = 0;
	for(int i = 0; i < maxn + 2; i++)
		d[i] = 0;
	for(int maxim = 3; maxim * 4 - 4 <= maxn; maxim++)
	{
		long long sum = maxim * 4 - 4;
		long long low = maxim;
		while(low > 2 && sum <= maxn)
		{
			d[sum]++;
			low -= 2;
			sum += low * 4 - 4;
		}
	}
	for(int i = 0; i <= maxn; i++)
		co += d[i];

	cout << co << endl;
}