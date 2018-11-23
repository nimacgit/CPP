#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 100 + 1000;
vector<int> adj[maxn];
int sum[maxn], ans[maxn];
bool seen[maxn], mark[maxn];
int n;


void dfs(int par, int v)
{
	sum[v] = 0;
	for(auto u : adj[v])
	{
		if(u != par && !mark[u])
		{
			dfs(v, u);
			sum[v]+=sum[u] + 1;
		}
	}
}

int getcen(int par, int v, int sz)
{
//	cerr << " getcenterrrrr " << v << " " << sz << endl;
	sz++;
	for(auto u : adj[v])
		if(!mark[u] && u != par && (sum[u] + 1) > sz / 2)
			return getcen(v ,u, sz - 1);
//	cerr << " ok " << endl;
	return v;
}

void go(int v, int h)
{
//	cerr << " test " << v << " " << h << " dfs " << endl;
	dfs(-1, v);
//	for(int i = 0; i < n; i++)
//		cerr << i + 1 << " " << sum[i] << endl;
	int f = getcen(-1, v, sum[v]);
//	cerr << " getcen " <<  f << endl;
	mark[f] = true;
	ans[f] = h;
	for(auto u:adj[f])
		if(!mark[u])
			go(u, h+1);
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(mark, 0, sizeof mark);
	memset(seen, 0, sizeof seen);
	for(int i = 0, x, y; i < n - 1; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	go(0, 0);
	for(int i = 0; i < n; i++)
		cout << (char)('A' + ans[i]) << " ";
	cout << endl;
}
