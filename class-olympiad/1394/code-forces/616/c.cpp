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
const int maxn = 1000;
bool seen[maxn + 1000][maxn + 1000];
pie par[maxn + 1000][maxn + 1000];
long long d[maxn + 1000][maxn + 1000];
int n, m;
char mat[maxn + 1000][maxn + 1000];

int bfs(int x, int y, int px, int py)
{
	int co = 1;
	seen[x][y] = true;
	par[x][y] = mp(px, py);
	if(x < n && mat[x + 1][y] == '.' && !seen[x + 1][y])
		co += bfs(x + 1, y, px, py);
	if(y < m && mat[x][y + 1] == '.' && !seen[x][y + 1])
		co += bfs(x, y + 1, px, py);
	if(x > 0 && mat[x - 1][y] == '.' && !seen[x - 1][y])
		co += bfs(x - 1, y, px, py);
	if(y > 0 && mat[x][y - 1] == '.' && !seen[x][y - 1])
		co += bfs(x, y - 1, px, py);
	return d[x][y] = co;
}

bool comp(pie u, pie o)
{
	if(u.first == o.first && u.second == o.second)
		return true;
	return false;
}

void cou(int x, int y)
{
	vector <pie> poss;
	int co = 0;
	if(x < n)
		if(mat[x + 1][y] == '.')
		{
			poss.push_back(mp(1, 0));
			co += d[par[x + 1][y].first][par[x + 1][y].second];
		}
	if(x > 0)
		if(mat[x  - 1][y] == '.')
		{
			poss.push_back(mp(-1, 0));
			co += d[par[x - 1][y].first][par[x - 1][y].second];
		}
	if(y < m)
		if(mat[x][y + 1] == '.')
		{
			poss.push_back(mp(0, 1));
			co += d[par[x][y + 1].first][par[x][y + 1].second];
		}

	if(y > 0)	
		if(mat[x][y - 1] == '.')
		{
			poss.push_back(mp(0, -1));
			co += d[par[x][y - 1].first][par[x][y - 1].second];
		}
	for(int i = 0; i < poss.size(); i++)
	{
		for(int j = i + 1; j < poss.size(); j++)
		{
			if(comp(par[x + poss[i].first][ y + poss[i].second], par[x + poss[j].first][ y + poss[j].second]))
			{
				co -= d[par[x+poss[i].first][y+poss[i].second].first][par[x+poss[i].first][y+poss[i].second].second];
				swap(poss[j], poss[poss.size() - 1]);
				poss.pop_back();
				j--;
			}
		}
	}
	mat[x][y] = char((co + 1) % 10 + '0');
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%s", mat[i]);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mat[i][j] == '.' && !seen[i][j])
				bfs(i, j, i, j);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mat[i][j] == '.')
				mat[i][j] = '.';
			else
				cou(i, j);
		}
		printf("%s\n", mat[i]);
	}
}

