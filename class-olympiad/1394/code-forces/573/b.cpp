#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 4000;
bool matr[maxn + 100][maxn + 100];
vector <int> list[maxn + 100];
int n, m, t, s;
int par[maxn + 100];
bool mark[maxn + 100];
int inf = 10000 * 10000;
int mini = inf;

void DFS(int v)
{
	mark[v] = true;
	for(int i = 0; i < list[v].size(); i++)
	{
		if(par[v] != -1)
		{
			if(matr[par[v]][list[v][i]])
			{
				int sum = list[v].size() + list[par[v]].size() + list[list[v][i]].size() - 6;
				if(sum < mini)
					mini = sum;
			}
		}
		if(!mark[list[v][i]])
		{
			par[list[v][i]] = v;
			DFS(list[v][i]);
		}
	}

}

int main()
{
	cin >> n >> m;
	for(int i = 0, v1, v2; i < m; i++)
	{
		scanf("%d", &v1);
		scanf("%d", &v2);
		v1--;
		v2--;
		matr[v1][v2] = matr[v2][v1] = true;
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	for(int i = 0; i < n; i++)
		par[i] = -1;
	for(int i = 0; i < n; i++)
	{
		if(!mark[i])
			DFS(i);
	}
	if(mini == inf)
		cout << -1 << endl;
	else
		cout << mini << endl;
	
}