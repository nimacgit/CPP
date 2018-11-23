#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>



using namespace std;

const int maxn = 500;
vector < pair<int, int> > d[maxn + 20][maxn + 20];
int parent[maxn + 20][maxn + 20];
int n, m;
int num1[maxn + 20], num2[maxn + 20];

void dynamic()
{
	for(int i = 0; i <= n; i++)	
	{
		d[i][0].push_back(make_pair(0, -1));
		parent[i][0] = -1;
	}
	for(int i = 0; i <= m; i++)	
	{
		d[0][i].push_back(make_pair(0, -1));
		parent[0][i] = -1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{

			if(num1[i - 1] == num2[j - 1])
			{
				d[i][j] = d[i - 1][j - 1];
				parent[i][j] = 2;
				int count = 0;
				for(int l = d[i][j].size() - 1; l > 0 && num1[i - 1] > d[i][j][l].second; l--)
				{
					count = d[i][j][l].first + 1;
					d[i][j].pop_back();
				}
				d[i][j].push_back(make_pair(count, num1[i - 1]));
				if(d[i][j][0].first <= count)
					d[i][j][0] = make_pair(count, num1[i - 1]);
			}
			else
			{
				if(d[i][j - 1][0].first > d[i - 1][j][0].first)
				{
					d[i][j] = d[i][j - 1];
					parent[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i - 1][j];
					parent[i][j] = 3;
				}
			}
		}
	}

}

void print(int a, int b)
{
	cerr << " test " << a << " " << b << "  " << parent[a][b]  << endl;
	if(parent[a][b] != -1)
	{
		if(parent[a][b] ==  1)
			print(a, b - 1);
		else if(parent[a][b] ==  2)
		{
			print(a - 1, b - 1);
			cout << num1[a - 1] << " ";
		}
		else if(parent[a][b] ==  3)
			print(a - 1, b);
	}
}


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &num1[i]);
	cin >> m;
	for(int i = 0; i < m; i++)
		scanf("%d", &num2[i]);
	dynamic();
	cout << d[n][m][0].first << endl;
	print(n, m);
	cout  << endl;

}
