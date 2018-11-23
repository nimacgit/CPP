#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 * 30 + 10;
vector <int> list[maxn];
vector<int> myque;
bool mark[maxn];
int color[maxn];
int co = 0;
bool fail = false;

int chang(int c)
{
	if(c == 0)
		return 1;
	return 0;
}

void dfs(int u, int c)
{
	if(color[u] == -1)
	{
		color[u] = c;
		mark[u] = true;
		for(int i = 0; i < list[u].size(); i++)
			dfs(list[u][i], chang(c));
	}
	else
		if(color[u] != c)
			fail = true;
}


int main()
{
	int n,m;
	cin >> n >> m;
	int x,y;
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		x--;
		y--;
		list[x].push_back(y);
		list[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
		color[i] = -1;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, 0);
	if(!fail)
	{
		cout << "yes" << endl;
		for(int i = 0; i < n; i++)
			if(color[i] == 0)
				co++;
		cout << co << endl;
		for(int i = 0; i < n; i++)
			if(color[i] == 0)
				cout << i + 1 << " ";
		cout << endl;
	}
	else
		cout << "no" << endl;
}