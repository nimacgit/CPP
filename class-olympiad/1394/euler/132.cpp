#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include "Bignumber.cpp"

using namespace std;

const int maxn = 1000 * 1000 * 10;
bool notprime[maxn + 10];
vector <int> primes;
const long long maxten = (long long)1000 * 1000 * 1000;

void find()
{
	for(int i = 2; i < maxn; i++)
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				notprime[i * j] = true;
		}
}

bool isok(int a)
{
	long long ten = maxten;
	a *= 9;
	long long sum = 10;
	long long baghi = 1;
	while(ten > 10)
	{
		baghi = sum;
		for(int i = 0; i < 9; i++)
			sum = (baghi * sum) % a;
		ten /= 10;
	}
	for(long long i = 0; i < ten; i++)
	{
		sum = (sum * baghi) % a;
		if(sum == 0)
			return false;
	}
	if(sum == 1)
		return true;
	return false;
}


int main()
{
	find();
	int co = 0;
	long long sum = 0;
	for(int i = 0; i < primes.size() && co < 40; i++)
	{
		if(isok(primes[i]))
		{
			cout << primes[i] << endl;
			co++;
			sum += primes[i];
		}
	}
	cout << sum << endl;
}