#include <iostream>
#include <string>

using namespace std;

const int maxn = 100 + 3;
string s;
int g[maxn][maxn];

int main()
{
	int n,m;
	unsigned long long sum = 0;
	cin >> n >> m;
	for(int i = 0 ; i <= n + 1; i++)
	{
		if(i != 0 && i != n + 1)
			cin >> s;
		for(int j = 0; j <= m + 1; j++)
		{
			if(i == 0 || i == n + 1 || j == 0 || j == m + 1)
				g[i][j] = 0;
			else
				g[i][j] = s[j - 1] - 48;
		}
	}
	/*
	for(int i = 0 ; i <= n + 1; i++)
	{
		for(int j = 0; j <= m + 1; j++)
		{
				cout << g[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(g[i][j] != 0)
				sum += 2;
			if(g[i][j] - g[i + 1][j] > 0)
				sum += g[i][j] - g[i + 1][j];
			if(g[i][j] - g[i - 1][j] > 0)
				sum += g[i][j] - g[i - 1][j];
			if(g[i][j] - g[i][j + 1] > 0)
				sum += g[i][j] - g[i][j + 1];
			if(g[i][j] - g[i][j - 1] > 0)
				sum += g[i][j] - g[i][j - 1];
		}
	}
	cout << sum << endl;



	
}