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
const int maxn = 10000;
bool seen[maxn];
int adj[maxn][4];
int adjsz[maxn];
int n, p;
int match[maxn];
int out[maxn];
vector<pie> hor, ver;
bool aug(int v)
{
	if(seen[v])
		return false;
	seen[v] = true;
	for(int i = 0; i < adjsz[v]; i++)
	{
		int u = adj[v][i];
		if(match[u] == -1 || aug(match[u]))
			return match[v] = u, match[u] = v, true;
	}
	return false;
}
int matching()
{
	bool found = true;
	while(found)
	{
		memset(seen, 0, sizeof seen);
		found = false;
		for(int i = 0; i < n * n; i += 2)
		{
				if((i / n) % 2 == 0)
				{
					if(match[i] == -1)
						found |= aug(i);
				}
				else
				{
					if((i + 1) % n != n - 1 || n % 2 != 1)
						if(match[i + 1] == -1)
							found |= aug(i + 1);
				}
		}
	}
}

void makeadj()
{
	for(int i = 0, x, y; i < n * n; i+=2)
	{
		bool flag = true;
		adjsz[i] = 0;
		int pos;
		if((i / n) % 2 == 0)
		{
			x = i / n;
			y = i % n;
			pos = i;
		}
		else
		{
			if((i+1) % n != n - 1 || n % 2 != 1)
			{
				x = i / n;
				y = (i+1) % n;
				pos = i + 1;
			}
			else
				flag = false;
		}
		if(flag&&!out[pos])
		{
			if(x > 0 && !out[n*(x - 1) + y])
			{
				adjsz[pos]++;
				adj[pos][adjsz[pos] - 1] = (x-1)*n + y;
			}
			if(y > 0 && !out[n*x + y - 1])
			{
				adjsz[pos]++;
				adj[pos][adjsz[pos] - 1] = x*n + y - 1;
			}
			if(y < n - 1 && !out[n * x + y + 1]) 
			{
				adjsz[pos]++;
				adj[pos][adjsz[pos] - 1] = n*x + y + 1;

			}
			if(x < n - 1 && !out[n * (x+1) + y])
			{
				adjsz[pos]++;
				adj[pos][adjsz[pos] - 1] = (x+1)*n + y;
			}
		}
	}
}


int main()
{
	cin >> n >> p; 
	for(int i = 0, x, y; i < p; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		out[y*n + x] = true;
	}
	makeadj();
	memset(match, -1 , sizeof match);
	matching();
	for(int i = 0; i < n * n; i+=2)
	{
		int pos = -1;
		if((i / n) % 2 == 0)
			pos = i;
		else
			if((i + 1)%n != n-1 || n % 2 != 1)
				pos = i + 1;
		if(pos != - 1 && !out[pos])
		{
			if(match[pos] == -1)
			{
				cout << "No" << endl;
				return 0;
			}
			else
			{
				int x[2], y[2];
				x[0] = pos / n;
				y[0] = pos % n;
				x[1] = match[pos] / n;
				y[1] = match[pos] % n;
				if(x[0] < x[1])
					ver.push_back(mp(x[0], y[0]));
				else if(x[0] > x[1])
					ver.push_back(mp(x[1], y[1]));
				else if(y[1] > y[0])
					hor.push_back(mp(x[0], y[0]));
				else 
					hor.push_back(mp(x[1], y[1]));
			}
		}
	}
	if(2*(hor.size() + ver.size()) + p != n * n)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << hor.size() << endl;
	for(int i = 0; i < hor.size(); i++)
		cout << hor[i].S + 1 << " " << hor[i].F + 1 << endl;
	cout << ver.size() << endl;
	for(int i = 0; i < ver.size(); i++)
		cout << ver[i].S + 1 << " " << ver[i].F + 1 << endl;

}
