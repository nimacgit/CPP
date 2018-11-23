#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long delta = 229939;
const long long maxn = 12299390;
long long facts[maxn];
bool notprime[maxn];
vector<long long> primes;
vector <long long> factors[maxn];
vector <long long> goodfact;
long long phies[maxn];
bool phis[maxn];

void findfact()
{
	for(long long i = 1; i < maxn; i++)
	{
		for(long long j = 2; j * i < maxn; j++)
			facts[i * j]++;
	}
}

void find(long long maxim)
{
	for(long long i = 2; i <= maxim; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(long long j = 2; j * i <= maxim; j++)
				notprime[i * j] = true;
		}
	}
}

void findfactors()
{
	for(long long i = 2; i < primes[primes.size() - 1]; i++)
	{
		if(!notprime[i])
			for(long long j = 1; j * i < primes[primes.size()]; j++)
				factors[i * j].push_back(i);
	}
}
long long phi(long long a)
{
	if(!phis[a])
	{
		long long p = a;
		for(long long i = 0; i < factors[a].size(); i++)
		{
			p *= (factors[a][i] - 1);
			p /= factors[a][i];
		}
		phies[a] = p;
		return p;

	}
	else
		return phies[a];
}

int main()
{
	findfact();
	for(long long i = 1; i < maxn; i++)
		if(facts[i] == 48)
			goodfact.push_back(i);
	cout << goodfact.size() << endl;
	cout << goodfact[0] << endl;
	long long sum = 0;
	for(long long i = 0; i <goodfact.size(); i++)
	{
		long long good = goodfact[i];
		long long maximum = maxn / good;
		find(maximum);
		for(long long j = 2; j < maximum; j++)
			sum += phi(j);
	}
	cout << sum << endl;
	/// 10 s
}
