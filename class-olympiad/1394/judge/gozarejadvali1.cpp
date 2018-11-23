#include <iostream>

using namespace std;

const int maxn = 1000;
int numb[maxn][maxn];
int d[maxn][maxn];

void gozar(int posi, int posj)
{
	d[posi][1] = numb[posi][1];
	for(int i = posi; i >= 1; i--)
	{
		for(int j = 1; j <= posj; j++)
		{
			if(i == posi)
			{
				if(j != 1)
					d[i][j] = d[i][j - 1] + numb[i][j];
			}
			else
				if(j == 1)
				{
					if(i != posi)
				 		d[i][j] = d[i + 1][j] + numb[i][j];
				}
				else
					d[i][j] = min(d[i + 1][j], d[i][j - 1]) + numb[i][j];
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> numb[i][j];
	gozar(n,m);
	/*
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
	*/
	cout << d[1][m] << endl;

}