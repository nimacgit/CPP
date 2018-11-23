#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 1e3;
int n, m, q;
pair<int, pie> h[maxn * maxn];
pie par[maxn][maxn];
int cmp;
int ans[maxn];

pie getpar(pie a)
{
	int i = a.F, j = a.S;
	if(par[i][j] == mp(i, j))
		return mp(i, j);
	return par[i][j] = getpar(par[i][j]);
}

void merge(pie i, pie j)
{
	i = getpar(i);
	j = getpar(j);
	if(i == j)
		return;
	par[i.F][i.S] = j;
}

void getans()
{
	cmp = 0;
	int pos = 0;
	for(int i = 710; i >= 0; i--)
	{
		while(h[pos].F > i && pos < n*m)
		{
			isunder[h[pos].S.F][h[pos].S.S] = true;
			if(h[pos].)
			pos++;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0, temp; j < m; j++)
		{
			cin >> temp;
			h[i * n + j] = mp(temp, mp(i, j));
		}
	sort(h, h + n * m);
	reverse(h, h + n);
	cin >> q;
	getans();
	for(int i = 0, temp; i < q; i++)
	{
		cin >> temp;
		cout << ans[temp] << endl;
	}
}
