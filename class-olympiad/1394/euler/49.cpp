#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 10;
vector<long long> primes;
bool  check[2 * maxn];

void find()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(!check[i])
		{
			if(i > 1000)
				primes.push_back(i);
			for(int j = 2; i * j <= 2 * maxn; j++)
				check[i * j] = true;
		}
	}
}

bool isper(int a, int b)
{
	int c[10];
	int d[10];
	for(int i = 0; i < 10; i++)
	{
		c[i] = 0;
		d[i] = 0;
	}
	while(a)
	{
		c[a % 10]++;
		a /= 10;
	}
	while(b)
	{
		d[b % 10]++;
		b /= 10;
	}
	for(int i = 0; i < 10; i++)
		if(c[i] != d[i])
			return false;
	return true;
}

int main()
{
	find();
	for(int i = 0; i < primes.size(); i++)
	{
		for(int j = i + 1; j < primes.size(); j++)
		{
			int next = primes[j] + primes[j] - primes[i];
			if(!check[next])
				if(isper(primes[i], primes[j]) && isper(next, primes[j]) && isper(next, primes[i]))
					cout << primes[i] << "  " << primes[j] << "  " << next << endl;
		}
	}
	
}