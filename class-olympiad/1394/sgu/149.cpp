#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;


class Node
{
public:
	int father;
	vector<int> son;

};


const int maxn = 1000 * 10;
bool mark[maxn + 100];
vector <int> adj[maxn + 100];
vector <int> w[maxn + 100];
int d1[maxn + 10], d2[maxn + 10];
int n;


void dfs1(int v)
{
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
		{
			d1[u] = d1[v] + w[v][i];
			dfs1(u);
		}
	}
}
void dfs2(int v)
{
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
		{
			d2[u] = d2[v] + w[v][i];
			dfs2(u);
		}
	}
}



int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int y, c;
		scanf("%d %d", &y, &c);
		y--;
		adj[i].push_back(y);
		adj[y].push_back(i);
		w[i].push_back(c);
		w[y].push_back(c);
	}
	//cerr << " check 1  " << endl;
	dfs1(0);
	int maxv = 0;
	for(int i = 0; i < n; i++)
	{
		if(d1[maxv] < d1[i])
			maxv = i;
	}
	//cerr << " check 2  " << endl;
	d1[maxv] = 0;
	fill(mark, mark + n, false);
	dfs1(maxv);
	maxv = 0;
	for(int i = 0; i < n; i++)
	{
		if(d1[maxv] < d1[i])
			maxv = i;
	}
	//cerr << " check 3  " << endl;
	fill(mark, mark + n, false);
	dfs2(maxv);
	for (int i = 0; i < n; i++) 
		cout << max(d1[i], d2[i]) << endl;

	
}