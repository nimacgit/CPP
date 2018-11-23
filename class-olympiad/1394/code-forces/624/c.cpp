#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000;
int n, m, x, y;
vector<int> adj[maxn];
int d[maxn];
char st[maxn];
bool seen[maxn];
int mat[maxn][maxn];
vector<int> as, cs;

void dfs(int v)
{
	as.push_back(v);
	seen[v] = true;
	st[v] = 'a';
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
			dfs(u);
	}
}

bool check1()
{
	for(int i = 0; i < as.size(); i++)
		for(int j = i + 1; j < as.size(); j++)
		{
			int v = as[i], u = as[j];
			if(mat[v][u] != 1)
				return true;
		}
	return false;
}

bool check2()
{
	for(int i = 0; i < n; i++)
		if(!seen[i])
		{
			st[i] = 'c';
			cs.push_back(i);
		}
	for(int i = 0; i < cs.size(); i++)
		for(int j = i + 1; j < cs.size(); j++)
		{	
			int v = cs[i], u = cs[j];
			if(mat[v][u] != 1)
				return true;
		}
	return false;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		y--;
		x--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		d[x]++;
		d[y]++;
		mat[x][y] = mat[y][x] = 1;
		if(d[x] == n - 1)
		{
			seen[x] = true;
			st[x] = 'b';
		}
		if(d[y] == n - 1)
		{
			seen[y] = true;
			st[y] = 'b';
		}
	}
	int k = 0;
	while(seen[k] && k < n)
		k++;
	if(k == n)
	{
		cout << "Yes" << endl;
		for(int i = 0; i < n; i++)
			cout << 'b';
		cout << endl;
		return 0;
	}
	dfs(k);
	if(check1())
	{
		cout << "No" << endl;
		return 0;
	}
	if(check2())
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++)
		cout << st[i];
	cout << endl;
	return 0;


}

