#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const long long maxn = 1000 * 1000 * 100  + 1;
bool notprime[maxn + 10];
vector <long long> primes;

void find()
{
	notprime[0] = notprime[1] = true;
	for(long long i = 2; i < maxn; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(long long j = 2; i * j < maxn; j++)
				notprime[i * j] = true;
		}
	}
}



int main()
{
	find();
	long long prime1, prime2;
	long long sum = 0, k = 7000009055738;
	bool flag;
	for(long long i = 0; i < primes.size(); i++)
	{
		prime1 = primes[i] + 1;
		flag = true;
		for(long long j = i + 1; j < primes.size() && flag ; j++)
		{
			prime2 = primes[j] + 1;
			if(prime2 * prime2 % prime1 == 0)
			{
				if(prime2 * prime2 / prime1 < maxn)
				{
					if(!notprime[prime2 * prime2 / prime1 - 1])
					{
						//cout << prime1 - 1 << "  " << prime2 - 1 << endl;
						sum += prime2 + prime1 + (prime2 * prime2 / prime1) - 3;
						if(sum > k)
						{
							cout << sum << endl;
						}
					}
				}
				else
					flag = false;
			}
		}
	}
	cout << sum << endl;
}