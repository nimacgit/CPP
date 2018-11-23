#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100;
vector <int> list[maxn], w[maxn];
const int inf = (1LL << 31) - 1;
bool mark[maxn];
int d[maxn], n, m, v;

void dijkstra(int u)
{
	for(int i = 0; i < maxn; i++)
		d[i] = inf;
	d[u] = 0;
	for(int i = 0; i < n; i++)
	{
		int minimum = inf;
		int minimum_index = 0;
		for(int j = 0; j < n; j++)
		{
			if(!mark[j] && d[j] < minimum)
			{
				minimum = d[j];
				minimum_index = j;
			}
		}
		mark[minimum_index] = true;
		for(int j = 0; j < list[minimum_index].size(); j++)
		{
			int p = list[minimum_index][j];
			if(d[p] > d[minimum_index] + w[minimum_index][j])
				d[p] = d[minimum_index] + w[minimum_index][j];
		}
	}
}



int main()
{
	cin >> n >> m >> v;
	v--;
	for(int i = 0; i < m; i++)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		x--;
		y--;
		list[x].push_back(y);
		list[y].push_back(x);
		w[x].push_back(weight);
		w[y].push_back(weight);
	}
	dijkstra(v);
	for(int i = 0; i < n; i++)
		cout << d[i] << endl;

}

