#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1200 * 100;
vector <long long> factors[maxn * 10];
bool notprime[maxn * 10];
vector<int> primes;


void find()
{
	factors[1].push_back(1);
	for(int i = 2; i < maxn * 10; i++)
		if(!notprime[i])
		{
			primes.push_back(i);
			for(long long j = 1; j * i < maxn * 10; j++)
			{
				notprime[i * j] = true;
				factors[i * j].push_back(i);
			}
		}
}

long long gc(long long a, long long b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

long long rad(long long a)
{
	long long sum = 1;
	for(int i = 0; primes[i] * primes[i] <= a && i < primes.size(); i++)
		if(a % primes[i] == 0)
			sum *= primes[i];
	return sum;
}


long long mul(long long a)
{
	if(a < 10 * maxn)
	{
		long long sum = 1;
		for(int i = 0; i < factors[a].size(); i++)
			sum *= factors[a][i];
		return sum;
	}
	return rad(a);
}

int main()
{
	long long sum = 0;
	find();
	cout << mul((long long)46354 * 46355) << endl;
	for(long long i = 2; i < maxn; i++)
	{
		for(long long j = i + 1; j + i < maxn; j++)
		{
			if(gc(i, j) == 1 && gc(i + j, j) == 1 && gc(i + j, i) == 1)
				if(mul(i * j * (i + j)) < i + j)
				{
					cout << i << "  " << j << "  " << mul(i * j * (i + j)) << endl;
					sum += i + j;
					cout << sum << endl;
				}
		}
	}
	cout << sum << endl;
}