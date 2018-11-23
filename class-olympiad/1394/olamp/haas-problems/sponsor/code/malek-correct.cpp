// .... .... .....!
// P..... C.....!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

inline int Abs (int v) { return v  < 0 ? -v : v; }

////////////////////////////////////////////////////////////////////////////////

struct twoSat {
	int N;
	vector<vector<int> > adj;

	vector<char> vis;
	int now;
	vector<int> index, lowlink;
	int comps;
	vector<int> comp;
	stack<int> st;
	vector<bool> active;

	void init (int _N)
	{
		N = _N;
		adj.resize (2*N);
		vis.resize (2*N);
		index.resize (2*N);
		lowlink.resize (2*N);
		comp.resize (2*N);
		active.resize (2*N);
		clear();
	}

	void clear()
	{
		fill (all(adj), vector<int>());
		fill (all(vis), 0);
		now = 0;
		fill (all(index), 0);
		fill (all(lowlink), 0);
		comps = 1;
		fill (all(comp), 0);
		st = stack<int>();
		fill (all(active), 0);
	}

	void addClause (int x, int y) // (1 <= |x|, |y| <= n) && (-x == !x)
	{
		x = (x>0 ? 2*x-2 : -2*x-1);
		y = (y>0 ? 2*y-2 : -2*y-1);
		adj[x].push_back (y ^ 1);
		adj[y].push_back (x ^ 1);
	}

	void Tarjan_DFS (int u)
	{
		vis[u] = 1;
		index[u] = lowlink[u] = now++;
		st.push (u);
		active[u] = true;
		for (int i = 0; i < (int)adj[u].size(); i++)
		{
			int v = adj[u][i];
			if (vis[v] == 0)
			{
				Tarjan_DFS (v);
				lowlink[u] = min (lowlink[u], lowlink[v]);
			}
			else if (active[v])
				lowlink[u] = min (lowlink[u], index[v]);
		}
		if (index[u] == lowlink[u])
		{
			while (st.top() != u)
			{
				comp[st.top()] = comps;
				active[st.top()] = false;
				st.pop();
			}
			comp[u] = comps;
			active[u] = false;
			st.pop();
			comps++;
		}
		vis[u] = 2;
	}

	bool solve ()
	{
		for (int i = 0; i < 2*N; i++)
			if (vis[i] == 0)
				Tarjan_DFS (i);

		for (int i = 0; i < 2*N; i += 2)
			if (comp[i] == comp[i^1])
				return false;

		return true;
	}
} TS;

const int maxn = 3 * 1000 + 10;

int n;
pii p[maxn];
int dis[maxn][maxn];
vector<int> color[maxn];

int cache[maxn*maxn/2];
int len;

bool check(int dist)
{
	TS.clear();

	rep(i, n) rep (j, i)
		if(dis[i][j] < dist)
			TS.addClause(-(i+1), -(j+1));
	rep(c, n)
		rep(i, sz(color[c]))
			rep(j, i)
				TS.addClause(color[c][i]+1, color[c][j]+1);
	return TS.solve();
}

int main() {
	ios::sync_with_stdio (false);

	int tmp;
	cin >> n >> tmp;
	rep(i, n) {
		int c;
		cin >> p[i].X >> p[i].Y >> c;
		c--;
		color[c].pb(i);
	}

	rep(i, n) rep(j, i) {
		dis[i][j] = dis[j][i] = Abs (p[i].X-p[j].X) + Abs (p[i].Y - p[j].Y);
		cache[len++] = dis[i][j];
	}

	sort(cache, cache+len);
	len = unique(cache, cache+len) - cache;

	TS.init(n);

	int lo = 0, hi = len;

	while(hi - lo > 1) {
		int md = (hi + lo) / 2;
		if(check(cache[md]))
			lo = md;
		else
			hi = md;
	}

	cout << fixed << setprecision (3);
	cout << cache[lo] << endl;

	{ int _; cin >> _; return 0; }
}
