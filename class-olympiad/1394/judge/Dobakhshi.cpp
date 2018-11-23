#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 * 1000 + 2;
vector <int> list[maxn];
bool mark[maxn];
vector<int> myque;
int h[maxn];


bool bfs(int s)
{
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
				for(int i = u - 1; i >= 0 && h[i] == h[u] ; i--)
				{
					for(int j = 0; j < list[u].size(); j++)
						if(list[u][j] == i)
						{
							cout << "gashtam nabud nagard nis..." << endl;
							return false;
						}
				}
			}
		}
	}
	return true;
}


int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		x--,y--;
		list[x].push_back(y);
		list[y].push_back(x);
	}
	if(bfs(x))
		cout << "2bakhshi bud..." << endl;
}