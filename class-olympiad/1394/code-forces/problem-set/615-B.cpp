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
const int maxn = 1000 * 100;
long long d[maxn + 100];
vector<int> adj[maxn + 100];
long long deg[maxn + 100];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		temp1--;
		temp2--;
		adj[max(temp1, temp2)].push_back(min(temp1, temp2));
		deg[temp1]++;
		deg[temp2]++;
	}
	int maxi = 0;
	for(int i = 0; i < n; i++)
	{
		d[i] = 1;
		for(int j = 0; j < adj[i].size(); j++)
			d[i] = max(d[i], d[adj[i][j]] + 1);
		if(d[i] * deg[i] > d[maxi] * deg[maxi])
			maxi = i;
	}
	cerr << maxi << endl;
	cout << d[maxi] * deg[maxi] << endl;

}
