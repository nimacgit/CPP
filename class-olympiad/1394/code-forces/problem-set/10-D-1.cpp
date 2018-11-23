#include <bits/stdc++.h>
#define mp(x) make_pair(#x)

using namespace std;
typedef pair<int,int> pii;


const int maxn = 500;
int d[maxn + 10][maxn + 10];
int par[maxn + 100][maxn + 100];
int s1[maxn + 100];
int s2[maxn + 100];
int n,m;
int lcis[maxn + 100];
long long inf ((LL)1 >> 31 - 10);

void dyn()
{
	for(int i = 0; i <= n; i++)
	{

		d[i][0] = d[0][i] = 0;
		par[0][i] = par[i][0] = -1;
	}
	int f1 = 0, f2 = 0;
	for(int i = 1; i <= m; i++)
	{
		if(s1[0] == s2[i])
		{
			f1 = 1;
			d[1][i] = 1;
		}
		else
			d[1][i] = f1;
		if(s1[i] == s2[0])
		{
			d[i][1] = 1;
			f2 = 1;
		}
		else	
			d[i][1] = f2;
		par[1][i] = par[i][1] =  -1;
	}
	for(int i = 2; i <= n; i++)
	{
		for(int i = 0; i <= m; i++)
			lcis[i] = inf;
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
			{
				int pos = lcis - lower_bound(lcis, lcis + j + 1, inf);
				if(pos != 0)

				

			}
			else
			{
				d[i - 1][j - 1] = d[i - 1][j];
				par[i - 1][j - 1] = par


			}
		}
	}


}


void print(int a)
{
	if(par[a] != -1)
		print(par[a]);
	cout << a << " ";
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &s1[i]);
	cin >> m;
	for(int i = 0; i < m; i++)
		scanf("%d", &s2[i]);
	dyn();
	cout << d[n][m].first << endl;
	print(lcis[n][m]);
	cout << endl;

}
