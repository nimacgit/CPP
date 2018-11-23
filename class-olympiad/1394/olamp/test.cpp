#include <iostream>


using namespace std;

const int maxn = 1000;
bool seen[maxn + 100];
vector<int> adj[maxn + 100];
int n, m, co;

void DFS(int v)
{
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
		{
			seen[u] = true;
			DFS(u);
		}
	}
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		if(!seen[i])
		{
			co++;
			DFS(i);
		}
	}


}
