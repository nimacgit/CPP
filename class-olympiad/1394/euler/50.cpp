#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000;
vector<long long> primes;
bool  check[maxn];

void find()
{
	for(long long i = 2; i <= maxn; i++)
	{
		if(!check[i])
		{
			primes.push_back(i);
			for(long long j = 2; i * j <= maxn; j++)
				check[i * j] = true;
		}
	}
}


long long summ(long long a, long long b)
{
	long long sum = 0;
	for(long long i = 0; i < b; i++)
		sum += (primes[a + i]);
	return sum;
}


int main()
{
	find();
	cout << summ(0,550) << endl;
	long long maxj = 0, maxsum = 0, maxi = 0;
	cout << primes.size() << endl;
	for(long long i = 0; i < 1000 && summ(0, i) < maxn; i++)
	{
		long long sum = 0;
		for(long long j = 0; j < primes.size() && (i + j + 1) < primes.size() && summ(j, i) < maxn; j++)
		{
			sum = 0;
			sum += summ(j, i);
			if(sum < maxn)
			{
				if(!check[sum])
				{
					maxj = j;
					maxsum = sum;
					maxi = i;
				}
			}
		}
		cout << maxsum << " " << maxi << endl;
	}

}