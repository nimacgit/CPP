#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 150 * 1000 + 100;
vector <int> list[maxn];
int w[maxn];
vector <int> edge[2];
const int inf = 1000;
int d[maxn], n, m;
set < pair <int, int> > myset;
int parent[maxn];
long long sum = 0;
bool mark[maxn];
int checked = 0;

void prime(int u)
{

	for(int i = 0; i < n; i++)
	{
		d[i] = inf;
		sum += inf;
		parent[i] = -1;
	}
	sum -= inf;
	d[u] = 0;
	mark[u] = true;
	myset.insert(make_pair(0, u));
	while(checked < n && !myset.empty())
	{
		int minimum_index = myset.begin() -> second;
		//cerr << "  i  " << i << " minimum " << minimum << "  ind " << minimum_index << endl;
		myset.erase(myset.begin());
		mark[minimum_index] = true;
		checked++;
		for(int j = 0; j < list[minimum_index].size(); j++)
		{
			int temp = list[minimum_index][j];
			int p = edge[0][temp];
			if(edge[0][temp] == minimum_index)
				p = edge[1][temp];
			if(d[p] > w[temp] && !mark[p])
			{
				myset.erase(make_pair(d[p],p));
				sum -= d[p];
				d[p] = w[temp];
				parent[p] = temp;
				sum += d[p];
				myset.insert(make_pair(d[p], p));
			}
		}
	}
}


int main()
{
	cin >> n >> m;
	int x, y, weight;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> weight;
		x--;
		y--;
		list[x].push_back(i);
		list[y].push_back(i);
		edge[0].push_back(x);
		edge[1].push_back(y);
		w[i] = weight;
	}
	prime(x);
	cout << sum << endl;
	vector <int> finaledge;
	for(int i = 0; i < n; i++)
		if(parent[i] != -1)
			finaledge.push_back(parent[i]);
	sort(finaledge.begin(), finaledge.end());
	for(int i = 0; i < finaledge.size(); i++)
		cout << finaledge[i] + 1 << " ";
	cout << endl;
}


