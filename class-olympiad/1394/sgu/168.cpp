#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 1000 + 2;
int a[maxn][maxn];
int b[maxn][maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for(int j = m; j > 0; j--)
	{
		for(int i = n; i > 0; i--)
		{
			b[i][j] = a[i][j];
			if(i != n)
				b[i][j] = min(b[i][j], b[i + 1][j]);
			if(i != 1 && j != m)
				b[i][j] = min(b[i][j], b[i - 1][j + 1]);
			else
				if(j != m)
					b[i][j] = min(b[i][j], b[i][j + 1]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		cout << endl;
	}
	
}