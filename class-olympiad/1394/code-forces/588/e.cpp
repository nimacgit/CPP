#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

int n;
const int maxn = 1000 * 100;
int n, m, q;
vector <int> mat[maxn + 100];
vector <int> people[maxn + 100];



void DFS(int v)
{
	fill(mark, mark + n, false);
	mark[v] = true;
	for(int i = 0; i < list[v].size(); i++)
	{
		if(!mark[list[v][i]])
		{
			DFS(list[v][i]);
			par[list[v][i]] = v;
		}
	}

}



int main()
{
	cin >> n >> m >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		mat[x].push_back(y);
		mat[y].push_back(x);
	}
	for(int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		people[x].push_back(i);
	}
	bfs();
	for(int i = 0; i < q; i++)
	{
		int u, v, a;
		scanf("%d %d %d", v, u, a);

	}


}