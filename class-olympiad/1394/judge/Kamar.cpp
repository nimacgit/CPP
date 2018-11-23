#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 + 2;
vector <int> list[maxn];
bool mark[maxn];
bool check[maxn][maxn];
vector<int> myque;
int h[maxn];
int parent[maxn];

vector<int> v[maxn];

void print(int a,int b, int c, int Vi)
{
	//cerr << a << " " << b << " " << Vi << endl;
	if(c == 1)
	{
		v[Vi].push_back(a);
		v[Vi].push_back(b);
		v[Vi].insert(v[Vi].begin(), parent[a]);
		int para = parent[parent[a]], parb = parent[b];
		for(; parb !=para; para = parent[para], parb = parent[parb])
		{
			v[Vi].insert(v[Vi].begin(),para);
			v[Vi].push_back(parb);
		}
		v[Vi].push_back(parb);
	}
	else
	{
		v[Vi].push_back(a);
		v[Vi].push_back(b);
		int para = parent[a], parb = parent[b];
		for(; parb !=para; para = parent[para], parb = parent[parb])
		{
			v[Vi].insert(v[Vi].begin(),para);
			v[Vi].push_back(parb);
		}
		v[Vi].push_back(parb);
	}
}



bool bfs(int s)
{
	myque.push_back(s);
	h[s] = 0;
	mark[s] = true;
	int maxhi = -1, nearh = -1;
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
				parent[u] = v;
				if(maxhi != -1 && h[u] > h[maxhi])
				{
					print(maxhi, nearh, 2, s);
					return true;
				}
				for(int l = myque.size() - 2; l >= 0 && h[u] >= 1 && (h[myque[l]] == h[u] || h[myque[l]] == h[u] - 1); l--)
				{
					//cout << h[u] << " u " << u  << " i " << i << " par " << parent[u] << endl;
					if(check[u][myque[l]] && parent[u] != myque[l])
					{
						if(h[myque[l]] == h[u] - 1)
						{
							print(u, myque[l], 1, s);
							return true;
						}
						else
						{
							maxhi = u;
							nearh = myque[l];
						}
					}
				}
			}
		}
		if(maxhi != -1)
		{
			print(maxhi, nearh, 2, s);
			return true;
		}
	}
	return false;
}

void reset()
{
	myque.clear();
	for(int i = 0; i < maxn; i++)
		mark[i] = false;
}

int main()
{
	int n,m;
	int x,y;
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{	
		cin>>x>>y;
		x--,y--;
		list[x].push_back(y);
		list[y].push_back(x);
		check[x][y] = check[y][x] = true;
	}
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
		reset();
		if(bfs(i))
			flag = true;
	}
	int minimum = 0;
	if(flag)
	{
		for(int i = 0; i < maxn; i++)
			if(v[i].size() > 0 && v[i].size() < v[minimum].size())
			{
				minimum = i;
			}
		cout << v[minimum].size() << endl;
		for(int i = 0; i < v[minimum].size(); i++)
			cout << v[minimum][i] + 1 << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;


}