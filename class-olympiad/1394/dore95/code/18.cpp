#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
int n;
const int maxn = 1010;
int a[maxn][maxn], d[maxn][maxn];
string s;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < n; j++)
		{
			if(s[j] == 'w')
			{
				a[i][j] = 0;	
				d[i][j] = 1;
			}
			else
			{
				a[i][j] = 1;
				d[i][j] = 0;
			}

		}
	}

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(d[i][j])
			{
				if(d[i - 1][j] == d[i][j - 1])
				{
					int sz = d[i - 1][j];
					if(d[i - sz][j - sz] > 0)
						d[i][j] = sz + 1;
					else
						d[i][j] = sz;
				}
				else
					d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
			}
		}

	}
	int maxi = 0, co = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(maxi < d[i][j])
			{
				maxi = max(maxi, d[i][j]);
				co = 1;
			}
			else if(maxi == d[i][j])
				co++;
		}
	cout << maxi << " " << co << endl;



}

