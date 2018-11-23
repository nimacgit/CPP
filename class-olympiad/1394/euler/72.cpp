#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const unsigned long long maxn = 1000 * 1000;
bool mark[maxn + 2];
vector<unsigned long long> fact[maxn + 2];


void find()
{
	for(unsigned long long i = 2; i <= maxn; i++)
	{
		if(!mark[i])
		{
			fact[i].push_back(i);
			for(unsigned long long j = 2; j * i <= maxn; j++)
			{
				mark[i * j] = true;
				fact[i * j].push_back(i);
			}
		}
	}
}

unsigned long long phi(long long a)
{
	int p = a;
	for(int i = 0; i < fact[a].size(); i++)
	{
		p /= fact[a][i];
		p *= (fact[a][i] - 1);
	}
	return p;
}


int main()
{
	find();
	unsigned long long sum = 0;
	for(int i = 2; i <= maxn; i++)
	{
		//cout << phi(i) << "  " << i << endl;
		sum += phi(i);
	}
	cout << sum << endl;
}