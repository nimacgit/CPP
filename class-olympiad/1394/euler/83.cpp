#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <set>

using namespace std;

const int maxn = 1000;
int w[maxn][maxn];
int d[maxn][maxn];
int n, m;
unsigned int inf = (unsigned)(1 << 31) - 1;
set <pair<int , pair <int,int> > > myset;


vector <pair <int, int> > findfriend(pair<int, int> pos)
{
	vector <pair<int,int> > frnd;
	if(pos.second > 0)
		frnd.push_back(make_pair(pos.first, pos.second - 1));
	if(pos.second < m - 1)
		frnd.push_back(make_pair(pos.first, pos.second + 1));
	if(pos.first > 0)
		frnd.push_back(make_pair(pos.first - 1, pos.second));
	if(pos.first < n - 1)
		frnd.push_back(make_pair(pos.first + 1, pos.second));
	return frnd;
}


void dijkstra()
{

	for(long long i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			d[i][j] = inf;
	d[0][0] = w[0][0];
	myset.insert( make_pair( w[0][0], make_pair(0,0) ) );
	for(long long i = 0; i < n * m && !myset.empty(); i++)
	{
		pair<int, int> minimum_index = myset.begin() -> second;
		myset.erase(myset.begin());
		vector < pair<int, int> > list = findfriend(minimum_index);
		for(long long j = 0; j < list.size(); j++)
		{
			pair<int, int> p = list[j];
			if(d[p.first][p.second] > d[minimum_index.first][minimum_index.second] + w[p.first][p.second])
			{
				myset.erase(make_pair(d[p.first][p.second],make_pair(p.first,p.second)));
				d[p.first][p.second] = d[minimum_index.first][minimum_index.second] + w[p.first][p.second];
				myset.insert(make_pair(d[p.first][p.second],make_pair(p.first, p.second)));
			}
		}
	}
}




int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> w[i][j];
	dijkstra();
	cout << d[n - 1][m - 1] << endl;

	
}