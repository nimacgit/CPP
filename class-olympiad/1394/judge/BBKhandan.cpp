#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 * 1000 + 2;
vector <int> list[maxn];
bool mark[maxn];
bool seen[maxn];
bool parent[maxn];
vector<int> myque;
int h[maxn];



int bfs(int s)
{
	int maxh = 0;
	myque.push_back(s);
	h[s] = 0;
	mark[s] = true;
	for(int i = 0; i < (int)myque.size(); i++)
	{
		int v = myque[i];
		for(int j = 0; j < (int)list[v].size(); j++)
		{
			int u = list[v][j];
			if(!mark[u])
			{
				myque.push_back(u);
				mark[u] = true;
				h[u] = h[v] + 1;
				maxh = max(maxh, h[u]);
			}
		}
	}
	return maxh;
}


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{	
		int x,y;
		cin>>x>>y;
		x--,y--;
		seen[x] = seen[y] = true;
		parent[x] = true;
		list[x].push_back(y);
		list[y].push_back(x);
	}
	int maxim = 0;
	for(int i = 0; i < n; i++)
	{
		if(seen[i] && !parent[i])
		{
			int nh = bfs(i);
			//cerr << nh << endl;
			if(nh > maxim)
				maxim = nh;
		}
	}
	cout << maxim << endl;
	
}