#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 402;
bool seen[maxn][maxn][28];
pair<pie, int> a[maxn*maxn*28];
vector <pair<pie, int> > adj[maxn][maxn][28];
vector<pie> adjg[maxn], radjg[maxn];
int h[maxn][maxn][28];
int n, m, d;
int dis[maxn][maxn];
int inf = 1e9;

void bfs()
{
	
	int pos = 0;
	for(int i = 0; i< n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < 28; k++)
				h[i][j][k] = inf;
	for(int i = 0; i < n; i++)
	{
			for(auto u : radjg[i])
			{
				a[pos] = mp(mp(i, i), u.S);
				seen[i][i][u.S] = true;
				h[i][i][u.S] = 0;
				pos++;
			}
			a[pos] = mp(mp(i, i), 27);
			seen[i][i][27] = true;
			h[i][i][27] = 0;
			pos++;
	}
	for(int i = 0; i <= pos; i++)
	{
		auto v = a[i];
		for(auto u : adj[v.F.F][v.F.S][v.S])
		{
			if(!seen[u.F.F][u.F.S][u.S])
			{
				if(u.F.S == u.F.F)
					h[v.F.F][v.F.S][v.S] + 1;
				h[u.F.F][u.F.S][u.S] = h[v.F.F][v.F.S][v.S] + 1;
				seen[u.F.F][u.F.S][u.S] = true;
				pos++;
				a[pos] = mp(mp(u.F.F, u.F.S), u.S);
			}
		}

	}
}


void ans()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dis[i][j] = h[i][j][27];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0,x , y; i < m; i++)
	{
		char c;
		cin >> x >> y >> c;
		x--;
		y--;
		adjg[x].pb(mp(y, c - 'a'));
		radjg[y].pb(mp(x, c - 'a'));
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			for(auto u : adjg[i])
				adj[u.F][j][u.S].pb(mp(mp(i, j), 27));
			for(auto u : radjg[j])
				adj[i][u.F][27].pb(mp(mp(i, j), u.S));
		}
	bfs();
	ans();
	cin >> d;
	int f, s;
	cin >> f;
	f--;
	for(int i = 1; i < d; i++)
	{
		cin >> s;
		s--;
		if(dis[f][s] == inf)
			cout << -1 << endl;
		else
			cout << dis[f][s] << endl;
		f = s;
	}
}
