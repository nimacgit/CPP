#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include "Bignumber.cpp"

using namespace std;

const int maxn = 1000 * 100;
bool notprime[maxn + 10];
vector <int> primes;
long long maxten = 10;

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
	while(ten > 1)
	{
		baghi = sum;
		for(int i = 0; i < 9; i++)
			sum = (baghi * sum) % a;
		if(sum == 0)
			return 0;
		ten /= 10;
	}
	if(sum == 1)
		return true;
	return false;
}


int main()
{
	find();
	long long sum = 0;
	for(int j = 0; j < 20; j++)
	{
		for(int i = 0; i < primes.size(); i++)
		{
			if(isok(primes[i]))
			{
				primes.erase(primes.begin() + i);
				i--;
			}
		}
		maxten *= 10;
	}
	for(int i = 0; i < primes.size(); i++)
		sum += primes[i];
	cout << sum << endl;
}