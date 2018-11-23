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
const int maxn =  200 * 1000 + 100;
int n, x, y;
vector<int> adj[maxn];
int same1 = -1, same2 = -1;
int conter[maxn];
bool tseen[maxn];
int th[maxn];
bool seen[maxn];
int maxh = 0;
int pos[maxn];
vector<int> num;

void pre()
{
	for(int i = 0; i < 
}


void tdfs(int v)
{
	if(th[v] > th[maxh])
		maxh = v;
	tseen[v] = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!tseen[u])
		{
			th[u] = th[v] + 1;
			tdfs(u);
		}
	}
}

long long dfs(int v)
{
	seen[v] = true;
	long long sum = 0;
	bool fson = false;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
		{
			if(!fson)
			{
				sum += x + dfs(u);
				fson = true;
			}
			else
				sum += y + dfs(u);
		}
	}
	return sum;
}



int main()
{
	cin >> n >> x >> y;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		conter[u]++;
		conter[v]++;
	}
	if(n == 2)
	{
		cout << x << endl;
		return 0;
	}
	if(n == 3)
	{
		if(x < y)
			cout << 2 * x << endl;
		else
			cout << x + y << endl;
		return 0;
	}
	if(n == 4)
	{
		int two = 0, one = 0;
		for(int i = 0; i < n; i++)
		{
			if(conter[i] == 2)
				two++;
			else if(conter[i] == 1)
				one++;
		}
		if(one == 2 && two == 2)
			cout << 3 * min(x, y) << endl;
		else
			cout << 2 * min(x, y) + max(x, y) << endl;
		return 0;
	}
	if(y == x)
	{
		cout << (long long)(n - 1) * (long long)x << endl;
		return 0;
	}
	if(x > y)
	{
		bool flag = false;
		for(int i = 0; i < n; i++)
			if(conter[i] == n - 1)
				flag = true;
		if(flag)
			cout << (long long)(n - 2) * (long long)y + (long long)x << endl;
		else
			cout << (long long)(n - 1) * (long long)y << endl;
		return 0;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			pos[i] = i;
			num.push_back(i);
		}
		while(!num.empty())
		{
			pre();
			tdfs(num[0]);	
			sum += dfs(maxh);
		}
	}

}
