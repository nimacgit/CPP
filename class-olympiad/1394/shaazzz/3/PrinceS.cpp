#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 100 * 1000;
int n, m;
int c[maxn + 100];
int w[maxn + 100];

int dfs(int s)
{
	if(s >= m)
		return 0;
	int use = dfs(s + 1);
	for(int i = 0; i < n; i++)
	{
		if(c[i] >= w[s])
		{
			c[i] -= w[s];
			use = max(use,1 + dfs(s + 1));
			c[i] += w[s];
		}		
	}
	return use;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(int i = 0; i < m; i++)
		scanf("%d", &w[i]);
	cout << dfs(0) << endl;
	return 0;
}
