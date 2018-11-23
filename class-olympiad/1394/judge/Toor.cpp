#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 + 4;
vector <int> list[maxn];
int mark[maxn][maxn];
vector <int> path;
int d[maxn];

void DFS(int v)
{
	//cerr << v + 1 << endl;
	for(int i = 0; i < list[v].size(); i++)
	{
		int u = list[v][i];
		if(mark[v][u])
		{
			mark[v][u]--;
			mark[u][v]--;
			DFS(u);
		}
	}
	path.push_back(v);

}





int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int x , y;
	if(m == 0 || n == 0)
	{
		cout << "YES SOLUTION" << endl;
		return 0;
	}
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		x--,y--;
		if(mark[x][y] == 0)
		{	
			list[x].push_back(y);
			list[y].push_back(x);
		}
		mark[y][x]++;
		mark[x][y]++;
		d[x]++;
		d[y]++;
	}
	int fard = 0;
	int fard1 = 0, fard2;
	for(int i = 0; i < n; i++)
	{
		if(d[i] % 2 == 1)
		{
			fard++;
			if(fard == 1)
				fard1 = i;
			else
				fard2 = i;
		}
	}
	//cerr << fard << endl;
	if(fard > 0 && fard != 2)
	{
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	DFS(fard1);
	if(path.size() != m + 1)
	{
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	cout << "YES SOLUTION" << endl;
	for(int i = 0; i < path.size() - 1; i++)
		cout << path[i] + 1 << " " << path[i + 1] + 1 << endl;
}