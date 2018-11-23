#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const long long maxn = 1000 * 100 + 10;
vector <long long> list[maxn], w[maxn];
const long long inf = (1LL << 60) - 1;
long long d[maxn], n, m, s, t;
long long parent[maxn];
set < pair <long long, long long> > myset;

void dijkstra(long long u)
{

	for(long long i = 0; i < maxn; i++)
	{
		d[i] = inf;
		parent[i] = -1;
	}
	d[u] = 0;
	myset.insert(make_pair(0, u));
	for(long long i = 0; i < n && !myset.empty(); i++)
	{
		long long minimum_index = myset.begin() -> second;
		//cerr << "  i  " << i << " minimum " << minimum << "  ind " << minimum_index << endl;
		myset.erase(myset.begin());
		for(long long j = 0; j < list[minimum_index].size(); j++)
		{
			long long p = list[minimum_index][j];
			if(d[p] > d[minimum_index] + w[minimum_index][j])
			{
				myset.erase(make_pair(d[p],p));
				d[p] = d[minimum_index] + w[minimum_index][j];
				parent[p] = minimum_index;
				myset.insert(make_pair(d[p], p));
			}
		}
	}
}


void print(long long v)
{
	if(v != -1)
	{
		print(parent[v]);
		cout << v + 1 << " ";
	}
}


int main()
{
	cin >> n >> m ;
	for(long long i = 0; i < m; i++)
	{
		long long x, y, weight;
		cin >> x >> y >> weight;
		x--;
		y--;
		list[x].push_back(y);
		list[y].push_back(x);
		w[x].push_back(weight);
		w[y].push_back(weight);
	}
	cin >> s >> t;
	t--;
	s--;
	dijkstra(s);
	if(d[t] == inf)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << d[t] << endl;
	print(t);
	cout << endl;


}

