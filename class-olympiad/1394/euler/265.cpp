#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const long long maxn = 5;
const long long maxsize = 32;
bool d[32];
bool use[maxsize];
vector <long long> goods;


void find(long long pos)
{
	if(pos == maxsize)
	{
		vector <int> check;
		for(long long i = maxsize - 4; i < maxsize; i++)
		{
			long long make = 0;
			for(long long j = 0; j < 5; j++)
				make = make * 2 + d[(i + j) % maxsize];
			if(use[make])
			{
				for(int i = 0; i < check.size(); i++)
					use[check[i]] = false;
				return;
			}
			check.push_back(make);
			use[make] = true;
		}
		for(int i = 0; i < check.size(); i++)
			use[check[i]] = false;
		long long sum = 0;
		for(int j = 0; j < maxsize; j++)
			sum = sum * 2 + d[j];
		goods.push_back(sum);
	}
	else
	{
		d[pos] = 0;
		int temp = 0;
		for(int i = pos - 4; i <= pos; i++)
			temp = temp * 2 + d[i];
		if(!use[temp])
		{
			use[temp] = true;
			find(pos + 1);
			use[temp] = false;
		}
		d[pos] = 1;
		temp += 1;
		if(!use[temp])
		{
			use[temp] = true;
			find(pos + 1);
			use[temp] = false;
		}
	}
}


int main()
{
	for(long long i = 0; i < maxn; i++)
		d[i] = 0;
	d[maxn] = 1;
	use[0] = use[1] = true;
	find(maxn + 1);
	long long sum = 0;
	for(int i = 0; i < goods.size(); i++)
		sum += goods[i];
	cout << sum << endl;
}