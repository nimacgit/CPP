#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<int> v;
const int maxn = 1000 * 1000 * 10;
bool mark[maxn];

bool check(int  a)
{
	int n = 0;
	int checkout[10];
	int bagh;
	for(int i = 0; i < 10; i++)
		checkout[i] = 0;
	while(a > 0)
	{
		bagh = a % 10;
		if(checkout[bagh] == 0 && bagh != 0)
			checkout[bagh]++;
		else
			return false;
		a /= 10;
		n++;
	}
	for(int i = 1; i <= n; i++)
		if(checkout[i] == 0)
			return false;
	return true;
}

void find()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!mark[i])
		{
			v.push_back(i);
			for(int j = 2; j * i < maxn; j++)
				mark[i * j] = true;
		}
	}
}

int main()
{
	find();
	int maxim;
	for(int i = 0; i < v.size(); i++)
	{
		if(check(v[i]))
			maxim = v[i];
	}
	cout << maxim << endl;

}