#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const unsigned long long maxn = 1000 * 1000 * 10;
bool mark[maxn];
vector<unsigned long long> fact[maxn];


void find()
{
	for(unsigned long long i = 2; i < maxn; i++)
	{
		if(!mark[i])
		{
			fact[i].push_back(i);
			for(unsigned long long j =2; j * i < maxn; j++)
			{
				mark[i * j] = true;
				fact[i * j].push_back(i);
			}
		}
	}
}

unsigned long long phi(long long a)
{
	int p = 1, q = 1;
	q = a;
	for(int i = 0; i < fact[a].size(); i++)
	{
		p *= (fact[a][i] - 1);
		q /= fact[a][i];
	}
	return p / q;
}

bool isper(int a, int b)
{
	int c[10], d[10];
	for(int i = 0; i < 10; i++)
		c[i] = d[i] = 0;
	while(a)
	{
		c[a % 10]++;
		a /= 10;
	}
	while(b)
	{
		d[b % 10]++;
		b /= 10;
	}
	for(int i = 0; i < 10; i++)
		if(c[i] != d[i])
			return false;
	return true;
}

int main()
{
	find();
	unsigned long long p = 1 , q = 0;
	for(int i = 5; i < maxn; i++)
	{
		int temp = phi(i);
		if(isper(temp, i))
		{
			if(i * q < temp * p)
			{
				p = i;
				q = temp;
			}
		}
	}
	cout << p << endl;
}