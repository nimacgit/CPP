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

const int maxn = 400;
int adj[maxn + 100][maxn + 100];
bool seen[maxn + 100];
vector <int> myque;
int n, m;
int h[maxn + 100];

int bfs(int i, int c)
{
	myque.push_back(i);
	seen[i] = true;
	for(int i = 0; i < myque.size(); i++)
	{
		int v = myque[i];
		for(int j = 0; j < n; j++)
		{
			if(adj[v][j] == c && !seen[j])
			{
				seen[j] = true;
				myque.push_back(j);
				h[j] = h[v] + 1;
				if(j == n - 1)
					return h[j];
			}
		}
	}
	return -1;
}



int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x][y] = adj[y][x] = 1;
	}
	int ans = 1;
	if(adj[0][n - 1])
	{
		h[0] = 0;
		ans = bfs(0, 0);
	}
	else
	{
		h[0] = 0;
		ans = bfs(0, 1);
	}
	cout << ans << endl;
}
