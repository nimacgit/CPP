#include <iostream>
#include <stdio.h>

using namespace std;

const int maxn = 1000 + 20;
int numb[maxn][maxn];
int d[maxn][maxn];
int mincell;

void gozar(int posi, int posj)
{
	for(int i = posi; i >= 1; i--)
	{
		for(int j = 1; j <= posj; j++)
		{
			if(i == posi)
			{
					d[i][j] = numb[i][j];
			}
			else
			{
				int back = 0;
				if(j != 1)
					mincell = min(d[i][j - 1], d[i + 1][j]);
				else
					mincell = d[i + 1][j];
				for(int k = j + 1; k <= posj; k++)
				{
					back += numb[i][k];
					mincell = min(mincell, (d[i + 1][k] + back));
				}
				d[i][j] = mincell + numb[i][j];
			}
		}
	}
}


int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &numb[i][j]);
	gozar(n,m);
	/*
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	*/
	mincell = d[1][1];
	for(int i = 2; i <= m; i++)
		mincell = min(mincell, d[1][i]);
	printf("%d \n", mincell); 

}