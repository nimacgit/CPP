#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = (long long) 1e18;
long long d[maxn][maxn];
bool seen[maxn][maxn];
int mo = 34019;
long long x;
long long ans = 1;

long long p(int i, int j)
{
	if(i == 0)
	{
		if(j == 0)
			return 1;
		else if(j == 1)
			return 3;
		else
			return 5;
	}
	if(i + 2 == j)
		return 5;
	if(j == 0)
		return 1;
	if(seen[i][j])
		return d[i][j];
	seen[i][j] = true;
	d[i][j] = p(i - 1, j) + p(i - 1 , j - 1);
	if(d[i][j] > mo)
	{
		d[i][j] -= mo;
		ans = (ans * x) % mo;
	}
	return d[i][j];
}

void fx()
{
	x = 1;
	for(int i = 0; i < mo; i++)
		x = (x * 17) % mo;
}

int main()
{
	fx();
	cout << p(maxn , 99) << endl;
}
