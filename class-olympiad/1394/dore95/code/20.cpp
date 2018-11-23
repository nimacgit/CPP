#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;

const int maxn = 3e4 + 100;
int mv[200];
pie a[maxn];
int b[maxn];
int n, m, k, sz;


int find(pie c)
{
//	cout << " check " << c.F << " " << c.S;
	int pos = lower_bound(a, a + n, c) - a;
	if(a[pos].F != c.F)
		return -1;
	if(a[pos].S < c.S)
		return -1;
	else if(a[pos].S == c.S)
	{
		if(pos < n - 1 && a[pos + 1].F == c.F)
			return a[pos + 1].S;
		else
			return -1;
	}

//	cout << " " << a[pos].S << endl;
//	cout << "fin" << endl;
	return a[pos].S;
}


int main()
{
	sz = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0, temp; i < n; i++)
	{
		cin >> temp;
		a[i] = mp(temp, i);
	}
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	for(int i = 0; i < m; i++)
	{
		int pos;
		if(sz == 0)
		{
			pos = find(mp(b[i], -1));
			if(pos != -1)
			{
				mv[sz] = pos;
				sz++;
			}

		}
		else
		{
			bool flag = false;
			pos = find(mp(b[i], -1));
			if(pos != -1 && pos < mv[0])
			{
				mv[0] = pos;
				flag = true;
			}
			int l = 0;
			if(flag)
				l++;
			for(; l < sz; l++)
			{
				pos = find(mp(b[i], mv[l]));
				if(pos != -1)
				{
					if(l == sz - 1)
					{
						mv[sz] = pos;
						if(sz > k - 1)
						{
							cout << "I don't feel like it" << endl;
							return 0;
						}
						sz++;
						l = sz + 2;
					}
					else if(pos < mv[l + 1])
					{
						mv[l + 1] = pos;
						l++;
					}
				}
			}
		}
	}
	cout << sz << endl;
}
