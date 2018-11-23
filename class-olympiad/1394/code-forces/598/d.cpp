#include <iostream>
#include <vector>
#define mp make_pair
#include <bits/stdc++.h>

#define val(X) [X/n][X%n]

using namespace std;

typedef pair<int,int> pie;
const int maxn = 1000;
int n, m, k;
char sh[maxn + 100][maxn + 100];
bool seen[maxn + 100][maxn + 100];
pie par[maxn + 100][maxn + 100];
int siz[maxn + 100][maxn + 100];
int fin[maxn + 100][maxn + 100];

void pre()
{
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
		{
			siz[i][j] = 1;
			par[i][j] = mp(i, j);
		}
}

pie fpar(pie x)
{
	if(par[par[x.first][x.second].first][par[x.first][x.second].second] == par[x.first][x.second])
	{
		return par[x.first][x.second];
	}
	else
		return par[x.first][x.second] = fpar(par[x.first][x.second]);
}

void merg(pie v, pie u)
{
	pie pv = fpar(v), pu = fpar(u);
	if(siz[pv.first][pv.second] >= siz[pu.first][pu.second])
	{
		par[pu.first][pu.second] = mp(pv.first, pv.second);
		siz[pv.first][pv.second] += siz[pu.first][pu.second];
	}
	else
	{
		par[pv.first][pv.second] = mp(pu.first, pu.second);
		siz[pu.first][pu.second] += siz[pv.first][pv.second];
	}
}


long long dfs(int x, int y)
{
	seen[x][y] = true;
	long long sum = 4;
	if(sh[x + 1][y] == '.')
	{
		sum--;
		if(!seen[x + 1][y])
		{
			sum += dfs(x + 1, y);
			merg(mp(x, y), mp(x + 1, y));
		}
	}
	if(sh[x - 1][y] == '.')
	{
		sum--;
		if(!seen[x - 1][y])
		{
			sum += dfs(x - 1, y);
			merg(mp(x, y), mp(x - 1, y));
		}
	}
	if(sh[x][y + 1] == '.')
	{
		sum--;
		if(!seen[x][y + 1])
		{
			sum += dfs(x, y + 1);
			merg(mp(x, y), mp(x, y + 1));
		}
	}
	if(sh[x][y - 1] == '.')
	{
		sum--;
		if(!seen[x][y - 1])
		{
			merg(mp(x, y), mp(x, y - 1));
			sum += dfs(x, y - 1);
		}
	}
	return sum;
}



int main()
{
	int n,m;
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
			sh[i][j] = s[j];
	}
	for(int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if(seen[x][y])
		{
			pie t = fpar(mp(x, y));
			cout << fin[t.first][t.second] << endl;
		}
		else
		{
			int sum = dfs(x, y);
			pie t = fpar(mp(x, y));
			fin[t.first][t.second] = sum;
			cout << sum << endl;
		}

	}
	
}
