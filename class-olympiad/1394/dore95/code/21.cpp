#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 5e3 + 100;
int h, w, k;
pie p[maxn];
bool seen[maxn];
int inf = 1e9;
long double dis[maxn];
long double ans;
int par[maxn];


long double getdis(int i, int j)
{
	long double y = p[i].S - p[j].S, x = p[i].F - p[j].F;
	if(i == k - 1 || i == 0 || j == 0|| j == k - 1)
		return sqrt(x*x);
	return sqrt(x * x + y * y);
}

void findmst()
{

	seen[0] = true;
	dis[0] = 0;
	for(int i = 0; i < k; i++)
			dis[i] = inf;
	ans = 0;
	par[0] = -1;
	int lasmin = 0;
	for(int i = 0; i < k - 1; i++)
	{
		int mini = 0;
		for(int j = 0; j < k; j++)
		{
			if(!seen[j])
				dis[j] = min(getdis(lasmin, j), dis[j]);
			if(((dis[j] < dis[mini]) || seen[mini]) && !seen[j])
				mini = j;
		}
		par[mini] = lasmin;
		if(mini == k - 1)
			return;
		seen[mini] = true;
		lasmin = mini;
	}
}

void getans(int a)
{
	if(par[a] == -1)
		return;
	ans = max(ans, dis[a]);
	getans(par[a]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w >> k;
	int minx = 0, maxx = 0;
	for(int i = 0, x, y; i < k; i++)
	{
		cin >> x >> y;
		p[i] = mp(x, y);
		if(x < p[minx].F)
			minx = i;
		if(x > p[maxx].F)
			maxx = i;
	}
	k += 2;
	if(k == 0)
	{
		p[k - 2] = mp(0,0);
		p[k - 1] = mp(h,0);
	}
	else
	{
		p[k - 2] = mp(0, p[minx].S);
		p[k - 1] = mp(h, p[maxx].S);
		swap(p[k - 2], p[0]);
	}
	findmst();
	getans(k - 1);
	cout << fixed << setprecision(2);
	cout << ans / 2 << endl;
	
}
