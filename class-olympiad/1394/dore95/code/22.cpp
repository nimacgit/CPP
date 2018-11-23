#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;

const int maxn = 400;
int adj[maxn][maxn];
int secadj[maxn][maxn];
bool seen[maxn];
int n, m, w, x, y;
int inf = 1e9;
int par[maxn];
int d[maxn];
int getans(int i, int j)
{
	return d[j] + min(adj[i][j], secadj[i][j]);
}
vector<pie> poss;

void dij()
{
	memset(seen, 0, sizeof seen);
	seen[0] = true;
	for(int i = 0; i < n; i++)
		d[i] = inf;
	d[0] = 0;
	par[0] = -1;
	int lastseen = 0;
	for(int k = 0; k < n - 1; k++)
	{
		int mini = 0;
		for(int i = 0; i < n; i++)
		{
			if(!seen[i])
			{
				if(d[i] > getans(i, lastseen))
				{
					par[i] = lastseen;
					d[i] = getans(i, lastseen);
				}
				if(seen[mini] || (d[i] < d[mini]))
					mini = i;

			}
		}
		seen[mini] = true;
		lastseen = mini;
	}
}

void getposs(int i)
{
	if(par[i] == -1)
		return;
	poss.pb(mp(i, par[i]));
	getposs(par[i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			secadj[i][j] = secadj[j][i] = adj[i][j] = adj[j][i]  = inf;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		x--;
		y--;

		if(secadj[x][y] > w)
		{
			if(adj[x][y] >= w)
			{
				secadj[x][y] = secadj[y][x] = adj[x][y];
				adj[x][y] = adj[y][x] = w;
			}
			else
				secadj[x][y] = secadj[y][x] = w;
		}
	}
	dij();
	int ans = d[n - 1];
	int minim = 0;
	getposs(n - 1);
	for(int i = 0; i < poss.size(); i++)
	{
		x = poss[i].F, y = poss[i].S;
		adj[x][y] *=2;
		adj[y][x] *=2;
		dij();
		adj[x][y] /=2;
		adj[y][x] /=2;
		if(minim < d[n - 1] - ans)
			minim = d[n - 1] - ans;
	}	
	if(minim >= inf)
		cout << 0 << endl;
	else
		cout << minim << endl;
}
