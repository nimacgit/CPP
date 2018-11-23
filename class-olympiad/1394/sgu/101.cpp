#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100 + 4;
vector <int> list[maxn];
int mark[maxn][maxn];
vector <int> path;
int d[maxn];
vector<int> checking;
bool marking[maxn + 3];

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


void find(int a, int b)
{
	for(int i = 0; i < checking.size(); i++)
	{
		if(!marking[i])
		{
			if(checking[i] == 10 * a + b)
			{
				marking[i] = true;
				cout << i + 1 << " + " << endl;
				return;
			}
			else if(checking[i] == 10 * b + a)
			{
				marking[i] = true;
				cout << i + 1 << " - " << endl;
				return;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n;
	m = n;
	int x , y;
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		if(mark[x][y] == 0)
		{	
			list[x].push_back(y);
			list[y].push_back(x);
		}
		checking.push_back(10 * x + y);
		mark[y][x]++;
		mark[x][y]++;
		d[x]++;
		d[y]++;
	}
	int fard = 0;
	int fard1 = x, fard2 = y;
	for(int i = 0; i <= 6; i++)
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
	if(fard > 0 && fard != 2)
	{
		cout << "No solution" << endl;
		return 0;
	}
	DFS(fard1);
	if(path.size() != m + 1)
	{
		cout << "No solution" << endl;
		return 0;
	}
	for(int i = 0; i < path.size() - 1; i++)
		find(path[i], path[i + 1]);
}