#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pos(x) (((x)/m + (x)% m)%2)
using namespace std;

typedef pair<int, int> pie;
int n, m;
const int maxn = 100 * 1000;
int adj[maxn][4];
int adjsz[maxn];
bool seen[maxn];
int match[maxn];
vector<int> vertex;
bool out[maxn];
bool guard[maxn];
int cnt = 0;




bool aug(int v)
{
	if(seen[v])
		return false;
	seen[v] = true;
	for(int i = 0; i < adjsz[v]; i++)
	{
		int u = adj[v][i];
		seen[u] = true;
		if(match[u] == -1 || aug(match[u]))	
			return match[v] = u,match[u] = v, true;
	}
	return false;
}

void matching()
{
	bool found = true;
	while(found)
	{
		found = false;
		memset(seen, 0, sizeof seen);
		for(int i = 0; i < vertex.size(); i++)
		{
			int u = vertex[i];
			if(match[u] == -1)
				found |= aug(u);
		}
	}
}


void makeadj()
{
	memset(match, - 1, sizeof match);
	for(int i = 0; i < n * m; i++)
	{
		if(pos(i) == 0 && !out[i])
			vertex.push_back(i);
		if(!out[i])
		{
			int x = i / m;
			int y = i % m;
			if(x < n - 1 && !out[(x+1)*m + y])
			{
				adj[i][adjsz[i]] = (x+1)*m + y;
				adjsz[i]++;
			}
			if(x > 0 && !out[(x-1)*m + y])
			{
				adj[i][adjsz[i]] = (x-1)*m + y;
				adjsz[i]++;

			}
			if(y > 0 && !out[x*m + y -1])
			{
				adj[i][adjsz[i]] = x*m + y - 1;
				adjsz[i]++;

			}
			if(y < m - 1 && !out[x*m + y + 1])
			{
				adj[i][adjsz[i]] = x*m + y + 1;
				adjsz[i]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0, temp; i < n * m; i++)
	{
		cin >> temp;
		if(!temp)
			out[i] = true;
	}
	makeadj();
	matching();
	memset(seen, 0, sizeof seen);
	for(int i = 0; i < (int)vertex.size(); i++)
	{
		int u = vertex[i];
		if(!out[u] && match[u] == -1)
			aug(u);

	}
	for(int i = 0; i < n * m; i++)
	{
		if(!out[i] && (pos(i) ^ seen[i]))
		{
			cnt++;
			guard[i] = true;
		}	
	}
	cout << cnt << endl;
	for(int i = 0; i < n * m; i++)
	{
		if(out[i])
			cout << '#';
		else if(guard[i])
			cout << 'G';
		else 
			cout << '.';
		if((i+1) % m == 0)
			cout << endl;
	}

}
