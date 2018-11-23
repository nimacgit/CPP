#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100 * 1000 + 2;
vector <int> list[maxn];
bool mark[maxn];
vector<int> myque;
int parent[maxn];
int h[maxn];

void print(int i)
{
	if(i != -1)
	{
		print(parent[i]);
		cout << i + 1 << " ";
	}
}

void bfs(int s)
{
	for(int i = 0; i < n; i++)
		h[i] = -1;
	for(int i = 0; i < n; i++)
		parent[i] = -1;
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
				parent[u] = v;
				mark[u] = true;
				h[u] = h[v] + 1;
			}
		}
	}
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
		list[x].push_back(y);
		list[y].push_back(x);
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	bfs(s);
	for(int i = 0; i < n; i++)
		cout << h[i] << " ";
	cout << endl;
	if(s == t)
		cout << s + 1 << endl;
	else if(parent[t] != -1)
		{
			print(t);
			cout << endl;
		}
}