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

const int maxn = 1000 * 1000;
vector <pie> adj[maxn + 100];
pair<long long, pie> d[maxn + 100];
int n;
bool mark[maxn + 100];
long long sum = 0;

pie dfs(int v)
{
	mark[v] = true;
	int maxoneind = v, maxtwoind;
	long long maxone = 0 ,maxtwo = 0;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i].first;
		if(!mark[u])
		{
			pie temp = dfs(u);
			temp.first += adj[v][i].second;
			if(temp.first >= maxone)
			{
				if(temp.first > maxone || temp.second < maxoneind)
				{
					maxtwo = maxone;
					maxtwoind = maxoneind;
					maxone = temp.first;
					maxoneind = temp.second;
				}
				else
				{
					if(maxtwo == temp.first)
					{
						if(maxtwoind > temp.second)
							maxtwoind = temp.second;
					}
					else
					{
						maxtwo = temp.first;
						maxtwoind = temp.second;
					}

				}

			}
			else if(temp.first > maxtwo)
			{
				maxtwoind = temp.second;
				maxtwo = temp.first;
			}
		}
	}
	d[v] = mp(maxtwo + maxone, mp(min(maxoneind, maxtwoind), max(maxoneind, maxtwoind)));
	return mp(maxone, maxoneind);
}


int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		x--;
		y--;
		adj[x].push_back(mp(y,c));
		adj[y].push_back(mp(x,c));
		sum += 2 * c;
	}
	dfs(0);
	int ind = 0;
	for(int i = 0; i < n; i++)
		if(d[i].first > d[ind].first)
			ind = i;
		else
			if(d[i].first == d[ind].first)
			{
				if(d[i].second.first < d[ind].second.first)
					ind = i;
				else
					if(d[i].second.first == d[ind].second.first)
						if(d[i].second.second < d[ind].second.second)
							ind = i;
			}
	cout  << d[ind].second.first + 1 << " " << d[ind].second.second + 1 << " " << sum - d[ind].first << endl;
}
