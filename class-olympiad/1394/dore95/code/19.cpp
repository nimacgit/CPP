#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;

const int maxn = 1e4 + 100;
long long d[2][maxn];
long long w[2][maxn];
string s, t;
long long mo = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	if(s[0] == t[0])
		d[0][0] = 1;
	w[0][0] = 1;
	for(int i = 1; i < t.length(); i++)
	{
		if(s[0] == t[i])
		{
			d[0][i] = 1;
			w[0][i] = 1;
			if(d[0][i - 1] == 1)
				w[0][i] += w[0][i - 1];
		}
		else
		{
			d[0][i] = d[0][i - 1];
			w[0][i] = w[0][i - 1];
		}
		w[0][i] %= mo;

	}	
	for(int i = 1; i < s.length(); i++)
	{
		if(s[i] == t[0])
		{
			d[i%2][0] = 1;
			w[i%2][0] = 1;
			if(d[(i+1)%2][0] == 1)
				w[i%2][0] += w[(i+1)%2][0];
		}
		else
		{
			d[i%2][0] = d[(i+1)%2][0];
			w[i%2][0] = w[(i+1)%2][0];
		}
		w[i%2][0] %= mo;
		for(int j = 1; j < t.length(); j++)
		{
			long long l = d[(i+1)%2][j];
			long long r = d[i%2][j - 1];
			long long u = d[(i+1)%2][j - 1];
			if(s[i] == t[j])
			{
				d[i%2][j] = u + 1;
				w[i%2][j] = w[(i+1)%2][j - 1];
				if(l == u + 1)
					w[i%2][j] += w[(i+1)%2][j];
				if(r == u + 1)
					w[i%2][j] += w[i%2][j - 1];
			}
			else
			{
				if(l == r)
				{
					w[i%2][j] = w[(i+1)%2][j] + w[i%2][j - 1];
					d[i%2][j] = r;
					if(u == r)
					{
						w[i%2][j] -= w[(i+1)%2][j - 1];
						while(w[i%2][j] < 0)
							w[i%2][j] += mo;
					}
				}
				else
				{
					if(r > l)
					{
						d[i%2][j] = r;
						w[i%2][j] = w[i%2][j-1];
					}
					else
					{
						d[i%2][j] = l;
						w[i%2][j] = w[(i+1)%2][j];
					}
				}
			}
			w[i%2][j] %= mo;
		}
	}
	cout << d[(s.length() - 1)%2][(t.length() - 1)] << " " << w[(s.length() - 1)%2][(t.length() - 1)] << endl;
}
