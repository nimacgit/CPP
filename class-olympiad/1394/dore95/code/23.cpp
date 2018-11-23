#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 2e3 + 10, maxm = 1e6 + 10, maxl = 15;
int par[maxn][maxl], maxim[maxn][maxl], mat[maxn][maxn];
int two[maxl], parent[maxn], d[maxn], h[maxn];
bool seen[maxn];
int inf = 1e9, n, m;
vector<pair<pie, int> > edge;
vector<int> adj[maxn];


void findmst()
{
	seen[0] = true;
	int lastseen = 0;
	d[0] = 0;
	seen[0] = true;
	for(int i = 1; i < n; i++)
	{
		int mini = 0;
		for(int i = 0; i < n; i++)
		{
			if(!seen[i])
			{
				if(mat[i][lastseen] != 0)
				{
					if(mat[i][lastseen] < d[i])
					{
						parent[i] = lastseen;
						d[i] = mat[i][lastseen];
					}
				}
				if(seen[mini] || (d[i] < d[mini]))
					mini = i;
			}
		}
		if(d[mini] == inf)
			return;
		seen[mini] = true;
		lastseen = mini;
	}
}

void pre()
{
	for(int i = 0; i < n; i++)
		d[i] = inf;
	two[0] = 1;
	for(int i = 1; i < maxl; i++)
		two[i] = two[i - 1] * 2;
}

void inp()
{
	cin >> n >> m;
	for(int i = 0, x, y, w; i < m; i++)
	{
		cin >> x >> y >> w;
		x--;
		y--;
		if(mat[x][y] == 0)
			mat[x][y] = mat[y][x] = w;
		else
			mat[x][y] = mat[y][x] = min(mat[x][y], w);
		edge.pb(mp(mp(x, y), w));
	}
}


void lca(int v)
{
	seen[v] = true;
	par[v][0] = parent[v];
	maxim[v][0] = d[v];
	for(int i = 1; i < maxl; i++)
	{
		par[v][i] = par[par[v][i - 1]][i - 1];
		maxim[v][i] = max(maxim[v][i - 1], maxim[par[v][i-1]][i - 1]);
	}
	for(auto u : adj[v])
		if(!seen[u])
		{
			h[u] = h[v] + 1;
			lca(u);
		}
			
}

int getmax(int v, int u)
{
	int maxi = 0;
	if(h[v] > h[u])
		swap(v, u);
	for(int i = maxl - 1; i >= 0; i--)
		if(h[par[u][i]] >= h[v])
		{
			maxi = max(maxi, maxim[u][i]);
			u = par[u][i];
		}
	if(v == u)
		return maxi;
	for(int i = maxl - 1; i >= 0; i--)
	{
		if(par[v][i] != par[u][i])
		{
			maxi = max(maxi, max(maxim[v][i], maxim[u][i]));
			v = par[v][i];
			u = par[u][i];
		}
	}
	maxi = max(maxi, max(maxim[v][0], maxim[u][0]));
	return maxi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	inp();
	pre();
	findmst();
	for(int i = 0; i < n; i++)
		if(!seen[i])
		{
			cout << "disconnected" << endl;
			return 0;
		}
	memset(seen, 0, sizeof seen);
	int maxi = 0;
	long long sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum += d[i];
		maxi = max(maxi, d[i]);
		adj[parent[i]].pb(i);
	}
	long long minsum = sum - 2 * maxi;
	memset(seen, 0, sizeof seen);
	parent[0] = 0;
	d[0] = 0;
	h[0] = 0;
	lca(0);
	for(int i = 0; i < m; i++)
	{
		if(edge[i].S >= maxi)
		{
			
			int temp = getmax(edge[i].F.F, edge[i].F.S);
			minsum = min(minsum, sum - temp - edge[i].S);
		}
	}
	cout << minsum << endl;
		
	
	
}
