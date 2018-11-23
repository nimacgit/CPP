#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 1010;
set<int, greater <int>> maxs;
set<int> mins;
int n, m, r, c;
int a[maxn][maxn];
pie pos[maxn * maxn];
int d[maxn][maxn];

bool isok(int p)
{
	int x = max(pos[p].F - r + 1, 0), y = max(pos[p].S - c + 1, 0);
	int maxx = min(n - 1, pos[p].F + r - 1), maxy = min(m - 1, pos[p].S + c - 1);
	if(a[x][y] == p)
		return true;
	if(a[x][y] > p)
		d[0][0] = 1;
	else
		d[0][0] = -1;
	for(int i = 1; y + i <= maxy; i++)
	{
		if(a[x][y + i] > p)
			d[0][i] = d[0][i - 1] + 1;
		else
			d[0][i] = d[0][i - 1] - 1;
		
	}
	for(int i = 1; x + i <= maxx; i++)
	{
		if(a[x+i][0] > p)
			d[i][0] = d[i - 1][0] + 1;
		else
			d[i][0] = d[i - 1][0] - 1;
		for(int j = 1; y+j <= maxy; j++)
		{
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			if(a[x+i][y+j] > p)
				d[i][j]++;
			else
				d[i][j]--;
		}
	}
	for(int i = pos[p].F - x; i < maxx - x + 1; i++)
	{
		for(int j = pos[p].S - y;j < maxy - y + 1; j++)
		{
			cerr << i << " " << j << " " << r << " " << c << endl;;
			if(d[i][j] - d[i - r + 1][j] - d[i][j - c + 1] + d[i - r + 1][j - c + 1] == -1)
				return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			pos[a[i][j]] = mp(i, j);
		}
	cin >> r >> c;
	int s = 1, t = n*m;
	while(s != t)
	{
		cerr << s << " " << t << endl;
		int mid = (s + t + 1)/2;
		cerr << isok(mid) << endl;
		if(isok(mid))
			s = mid;
		else
			t = mid - 1;
	}
	cout << s << endl;
}
