#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 1000;
bool notprime[maxn + 10];
vector <pair<int, int> > prime;


void find()
{
	int ten = 10;
	for(int i = 2; i <= maxn; i++)
	{
		if(!notprime[i])
		{
			if(i > ten)
				ten *= 10;
			prime.push_back(make_pair(i,ten));
			for(int j = 2; j * i <= maxn; j++)
				notprime[i * j] = true;
		}
	}
}


long long findmax(pair<int, int> a, pair<int, int> b)
{
	long long sum = b.first;
	while(sum % a.second != a.first)
		sum += b.first;
	return sum;
}


int main()
{
	find();
	long long sum = 0;
	for(int i = 2; i < prime.size() - 1; i++)
	{
		cout << i << endl;
		sum += findmax(prime[i], prime[i + 1]);
	}
	cout << sum << endl;
}