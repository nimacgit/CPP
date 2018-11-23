#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stack>


using namespace std;

const int maxn = 200;
int matrix[maxn + 10][maxn + 10];
vector <pair<int,int> > graph[maxn + 10];
vector <pair<int, int> > mystack;
const int maxval = 1 << 30;
int h[maxn + 10][3];
int n, m;

void bfs()
{
	mystack.push_back(make_pair(0,0));
	h[0][0] = h[0][1] = h[0][2] = 0;
	for(int i = 0; i < mystack.size(); i++)
	{
		int v = mystack[i].first;
		int vcol = mystack[i].second;
		for(int j = 0; j < graph[v].size(); j++)
		{
			int u = graph[v][j].first;
			int ucol = graph[v][j].second;
			if(ucol != vcol && matrix[v][u] > 0)
			{
				mystack.push_back(make_pair(u, ucol));
				h[u][ucol - 1] = min(h[v][vcol - 1] + 1, h[u][ucol - 1]);
				matrix[v][u]--;
			}
		}
	}

}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		h[i][0] = h[i][1] = h[i][2] = maxval;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		matrix[a][b]++;
		graph[a].push_back(make_pair(b, c));
	}
	bfs();
	if(h[n - 1][0] == maxval && h[n - 1][1] == maxval && h[n - 1][2] == maxval)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << min(min(h[n - 1][0], h[n - 1][1]), h[n - 1][2]) << endl;
}