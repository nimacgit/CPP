#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000 * 10;
vector <long long> primes;
bool notprime[maxn];

void find()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				notprime[i * j] = true;
		}
	}
}

long long findr(long long pos)
{
	long long num = primes[pos];
	long long sum = 0;
	long long p1 = 1;
	long long mo = num * num;
	for(int i = 0; i <= pos; i++)
	{
		p1 *= (num - 1);
		p1 %= mo;
	}
	sum += p1;
	p1 = 1;
	for(int i = 0; i <= pos; i++)
	{
		p1 *= (num + 1);
		p1 %= mo;
	}
	sum = (sum + p1) % mo;
	return sum;
}

int main()
{
	find();
	cout << findr(2) << endl;
	for(int i = 0; i < maxn; i++)
		if(findr(i) > 10000000000)
			cout << i << endl;
}