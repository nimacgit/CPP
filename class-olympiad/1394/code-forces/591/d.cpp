#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000;
int n, m;
bool mark[maxn];
vector<int> myque;
char ma[maxn + 100][maxn + 100];
vector<int> adj[maxn * maxn];
int minim = 1000 * 1000;
int cit = 0;

bool bfs(int s)
{
	int cocit = 0;
	myque.push_back(s);
	mark[s] = true;
	for(int i = 0; i < (int)myque.size(); i++)
	{
		int v = myque[i];
		if(ma[v / n][v % n] == '1' || ma[v / n][v % n] == '2' || ma[v / n][v % n] == '3')
			cocit++;
		for(int j = 0; j < (int)adj[v].size(); j++)
		{
			int u = adj[v][j];
			if(!mark[u])
			{
				myque.push_back(u);
				mark[u] = true;
			}
		}
	}

	if(cocit == cit)
	{
		minim = myque.size() - cit;
		return true;
	}
	return false;
}


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> ma[i][j];
			if(ma[i][j] == '1' || ma[i][j] == '2' || ma[i][j] == '3')
				cit++;
		}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i > 0)
				if(ma[i][j] != '#' && ma[i - 1][j] != '#')
				{
					adj[n * i + j].push_back(i * n + j - n);
					adj[i * n + j - n].push_back(i * n + j);
				}	
			if(j > 0)
				if(ma[i][j] != '#' && ma[i][j - 1] != '#')
				{
					adj[n * i + j].push_back(i * n + j - 1);
					adj[i * n + j - 1].push_back(i * n + j);
				}
			if(i < n)
				if(ma[i][j] != '#' && ma[i + 1][j] != '#')
				{
					adj[n * i + j].push_back(i * n + j + n);
					adj[i * n + j + n].push_back(i * n + j);
				}	
			if(j < m)
				if(ma[i][j] != '#' && ma[i][j + 1] != '#')
				{
					adj[n * i + j].push_back(i * n + j + 1);
					adj[i * n + j + 1].push_back(i * n + j);
				}
		}
	}
	for(int i = 0; i < maxn * maxn; i++)
	{
		if(!mark[i])
			if(bfs(i))
			{
				cout << minim << endl;
				return 0;
			}

	}
	cout << -1 << endl;
}
