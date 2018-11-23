#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 1000 * 1000;
typedef pair<int, int> pii;
#define mp make_pair 
long long n;
bool notp[maxn + 10];
vector<int> primes;
bool numprimes[maxn + 10];

void find()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(!notp[i])
		{
			primes.push_back(i);
			for(int j = 2; i * j <= maxn; j++)
				notp[i * j] = true;
		}
	}
}


int main()
{
	cin >> n;
	find();
	fill(numprimes, numprimes + maxn + 10, 0);
	for(int i = 0; i < primes.size(); i++)
	{
		while(n % primes[i] == 0)
		{
			numprimes[i] = true;
			n /= primes[i];
		}
	}
	long long fnum = n;
	for(int i = 0; i < primes.size(); i++)
		if(numprimes[i])
			fnum *= primes[i];
	cout << fnum << endl;



	
}