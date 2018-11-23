#include <iostream>

using namespace std;

const int maxn = 1000 + 2;
int d[maxn][maxn];
int par[maxn][maxn];
string s1, s2;
int n, m;

void bzm()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
			{
				d[i][j] = d[(i - 1)][j - 1] + 1;
				par[i][j] = 2;
			}
			else
			{
				d[i][j] =  max(d[(i - 1)][j], d[i][j - 1]);
				if(d[i][j] == d[(i - 1)][j])
					par[i][j] = 3;
				else
					par[i][j] = 1;
			}
			//cout << d[i][j] << " ";
		}
		//cout << endl;
	}
}

void print(int i, int j)
{
	if(par[i][j] != 0)
	{
		if(par[i][j] == 1)
		{
			print(i, j - 1);
		}
		else 
		{
			if(par[i][j] == 2)
			{
				print(i - 1, j - 1);
			}
			else 
			{
				print(i - 1, j);
			}
		}
		if(s1[i - 1] == s2[j - 1])
			cout << s1[i - 1];
	}
}

int main()
{
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	d[0][0] = d[1][0] = d[0][1] = 0;
	bzm();
	if(d[n][m] == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	print(n, m);
	cout << endl;

}