#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 * 10;
vector <long long> v;
int d[maxn];

bool isper(long long a, long long b)
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
	for(long long i = 1; i < maxn; i++)	
		v.push_back(i * i * i);
	for(int i = 0; i < v.size(); i++)
	{
		if(i > 0)
			if(d[i - 1] == 4)
				cout << v[i - 1] << endl;
		for(int j = i + 1; j < v.size(); j++)
		{
			if(isper(v[i], v[j]))
			{
				d[i]++;
				d[j]++;
			}
		}
	}

}