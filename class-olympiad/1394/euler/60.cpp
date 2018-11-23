#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <map>

using namespace std;

const int maxn = 1000 * 30;
bool notprime[maxn];
vector<pair<long long, long long> > prime;
const int maxsetsize = 3245;
vector <int> sets[maxsetsize];
bool issetprime[maxsetsize][maxsetsize];


void find()
{
	long long dah = 1;
	for(long long i = 2; i < maxn; i++)
	{
		if(!notprime[i])
		{
			if(dah <= i)
				dah *= 10;
			prime.push_back(make_pair(i, dah));
			for(long long j = 2; j * i < maxn; j++)
				notprime[i * j] = true;
		}
	}
}


bool isprime(long long a)
{
	if(a < maxn)
		return !notprime[a];
	for(int i = 0; i < prime.size() && prime[i].first * prime[i].first < a; i++)
		if(a % prime[i].first == 0)
			return false;
	return true;
}

bool isok(pair <long long,long long> a, pair<long long,long long> b)
{
	if(isprime(a.first * b.second + b.first) && isprime(a.second * b.first + a.first))
		return true;
	return false;
}

int main()
{
	find();
	cout << prime.size() << endl;
	for(int i = 0; i < prime.size(); i++)
	{
		for(int j = i - 1; j >= 0; j--)
			if(isok(prime[i], prime[j]))
			{
				issetprime[i][j] = issetprime[j][i] = true;
				sets[i].push_back(j);
			}
	}
	for(int i = 0; i < maxsetsize; i++)
	{
		for(int a1 = 0; a1 < sets[i].size(); a1++)
		{
			for(int a2 = a1 + 1; a2 < sets[i].size(); a2++)
			{
				for(int a3 = a2 + 1; a3 < sets[i].size() && issetprime[sets[i][a1]][sets[i][a2]]; a3++)
				{
					for(int a4 = a3 + 1; a4 < sets[i].size() && issetprime[sets[i][a1]][sets[i][a3]] && issetprime[sets[i][a2]][sets[i][a3]] ; a4++)
					{
						if(issetprime[sets[i][a1]][sets[i][a4]] && issetprime[sets[i][a2]][sets[i][a4]]  && issetprime[sets[i][a3]][sets[i][a4]])
							cout << prime[i].first << "  " << prime[sets[i][a1]].first << "   " << prime[sets[i][a2]].first << "    " << prime[sets[i][a3]].first << "   " << prime[sets[i][a4]].first << endl;
					}
				}
			}
		}
	}
}