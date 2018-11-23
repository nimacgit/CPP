#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000 * 100;
bool isnotprime[maxn];
vector <long long> primes;

void find()
{
	for(long long i = 2; i < maxn / 2; i++)
	{
		if(!isnotprime[i])
		{
			primes.push_back(i);
			for(long long j = 2; j * i <= maxn / 2; j++)
				isnotprime[i * j] = true;
		}
	}
}

int main()
{
	long long co = 0;
	find();
	cout << primes.size() << endl;
	for(long long i = 0; i < primes.size(); i++)
	{
		long long j = 0;
		while(primes[i] * primes[j] < maxn && j <= i)
			j++;
		co += j;
	}
	cout << co << endl;
}
