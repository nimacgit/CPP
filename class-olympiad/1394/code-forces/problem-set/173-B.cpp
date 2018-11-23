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
const int maxn = 1000 * 1000 + 100;
vector<int> d[maxn];
int h[maxn];
bool mark[maxn];
queue <int> myq;
int n, m;

void bfs()
{
	h[0] = 1;
	myq.push(0);
	mark[0] = true;
	while(!myq.empty())
	{
		int v = myq.front();
		myq.pop();
		for(auto u : d[v])
			if(!mark[u])
			{
				myq.push(u);
				mark[u] = true;
				h[u] = h[v] + 1;
			}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			if(temp == '#')
			{
				d[i].push_back(n + j);
				d[n + j].push_back(i);
			}
		}
	bfs();
	cout << h[n - 1] - 1 << endl;
}
