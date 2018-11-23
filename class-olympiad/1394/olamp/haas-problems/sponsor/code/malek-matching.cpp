// .... .... .....!
// ...... ......!

#include <bits/stdc++.h>

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

const int maxn = 3000 + 10;

int n;
pii p[maxn];
int col[maxn];
vector<int> color[maxn];
vector<pair<int, pii> > e;

vector<int> adj[maxn];
int coldel[maxn];

int colmark[maxn], curmark;
int tmpmatch[maxn];

void go (int v)
{
	if (coldel[col[v]] == -1 || coldel[col[v]] == v)
	{
		coldel[col[v]] = v;
		return;
	}
	int u = coldel[col[v]];
	coldel[col[v]] = v;
	for (int i = 0; i < (int)adj[u].size(); i++)
		go (adj[u][i]);
}

bool can (int v)
{
	if (colmark[col[v]] == curmark)
		return tmpmatch[col[v]] == v;
	if (coldel[col[v]] == -1 || coldel[col[v]] == v)
		return true;

	colmark[col[v]] = curmark;
	tmpmatch[col[v]] = v;

	int u = coldel[col[v]];
	bool yes = true;
	for (int i = 0; i < (int)adj[u].size(); i++)
		yes &= can (adj[u][i]);
	return yes;
}

int main() {
	ios::sync_with_stdio (false);

	int tmp;
	cin >> n >> tmp;
	rep (i, n)
	{
		cin >> p[i].X >> p[i].Y >> col[i];
		col[i]--;
		color[col[i]].pb (i);
	}

	rep (i, n) rep (j, i) e.pb (mkp (Abs (p[i].X - p[j].X) + Abs (p[i].Y - p[j].Y), pii (j, i)));
	sort (all(e));

	memset (coldel, -1, sizeof coldel);

	int ans = 0;

	for (int z = 0; z < sz(e); z++)
	{
		int v = e[z].Y.X, u = e[z].Y.Y;
		adj[v].push_back (u);
		adj[u].push_back (v);

		++curmark;
		if (can (v)) { go (v); continue; }
		++curmark;
		if (can (u)) { go (u); continue; }
		
		ans = e[z].X;
		break;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
