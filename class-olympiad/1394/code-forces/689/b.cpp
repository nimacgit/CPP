#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 3e5;
vector<int> adj[maxn];
int d[maxn];
deque<int> que;
bool seen[maxn];
int n;

void bfs()
{
	que.push_back(0);
	seen[0] = true;
	while(!que.empty())
	{
		int v = que.front();
		for(auto u : adj[v])
		{
			if(!seen[u])
			{
				seen[u] = true;
				d[u] = d[v] + 1;
				que.push_back(u);
			}
		}
		que.pop_front();
	}
}



int main()
{
	cin >> n;
	adj[0].push_back(1);
	adj[n - 1].push_back(n - 2);
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		temp--;
		adj[i].push_back(temp);
		if(i != n - 1)
		{
			adj[i].push_back(i + 1);
			adj[i].push_back(i - 1);
		}
		
	}
	bfs();
	for(int i = 0; i < n; i++)
		cout << d[i] << " ";
	cout << endl;
}
