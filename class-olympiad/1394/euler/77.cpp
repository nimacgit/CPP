#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 10;
const int lim = 5000;
bool notprime[maxn + 10];
vector <int> primes;
int d[maxn];


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


int dynamic()
{
	d[0] = 1;
	d[1] = 0;
	for(int i = 0; i < primes.size(); i++)
	{
		for(int j = primes[i]; j < maxn; j++)
			d[j] += d[j - primes[i]];
	}
	for(int i = 2; i < maxn; i++)
		if(d[i] > lim)
			return i;
}

int main()
{
	find();
	cout << dynamic() << endl;
}