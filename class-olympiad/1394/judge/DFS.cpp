#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int maxn = 1000 * 100 + 3;
vector <int> list[maxn];
int n, m, t, s;
int par[maxn];
bool mark[maxn];


void DFS(int v)
{
	mark[v] = true;
	for(int i = 0; i < list[v].size(); i++)
	{
		if(!mark[list[v][i]])
		{
			DFS(list[v][i]);
			par[list[v][i]] = v;
		}
	}

}

void print(int s)
{
	if(s != -1)
	{
		print(par[s]);
		cout << s + 1 << " ";
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
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	cin >> s >> t;
	s--;
	t--;
	for(int i = 0; i < n; i++)
		par[i] = -1;
	DFS(s);
	bool flag = false;
	if(par[t] != -1)
		flag = true;
	int sum = 1;
	for(int i = 0; i < n; i++)
		if(!mark[i])
		{
			DFS(i);
			sum++;
		}
	cout << sum << endl;
	if(flag)
	{
		print(t);
		cout << endl;
	}
	else
		if(s == t)
			cout << s + 1 << endl;
}