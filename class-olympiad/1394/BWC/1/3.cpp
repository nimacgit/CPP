#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 1000 * 100;
int n, m;
bool use[maxn + 100];
set <int> uses;
int par[maxn];

int gpar(int x)
{
	if(par[x] != x)
		return par[x] = gpar(par[x]);	
	return x;
}

void merge(int x, int y)
{
	y = gpar(y);
	x = gpar(x);
	par[x] = y;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < maxn; i++)
		par[i] = i;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if(gpar(x) != gpar(y))
			merge(x, y);
		else
			uses.insert(i + 1);
	}
	cout << m - n + 1 << endl;
	while(!uses.empty())
	{
		printf("%d ", *uses.begin());
		uses.erase(uses.begin());
	}
	cout << endl;
}
