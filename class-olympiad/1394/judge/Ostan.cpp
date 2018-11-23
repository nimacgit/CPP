#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <stack>
#include <string>
using namespace std;


const int maxn = 1000 * 100;
bool mark[maxn + 100];
vector <int> mylist[maxn + 10], revlist[maxn + 10];
bool mark_rev[maxn + 100];
vector <int> finish;
int co = 0, n, m;
vector <int> com[maxn + 100];
vector <int> temp;
vector<pair<int,int> > checking;
string s;

void DFS(int u)
{
	mark[u] = true;
	for(int i = 0; i < mylist[u].size(); i++)
		if(!mark[mylist[u][i]])
			DFS(mylist[u][i]);
	finish.push_back(u);
}

void DFS_rev(int u)
{
	mark_rev[u] = true;
	for(int i = 0; i < revlist[u].size(); i++)
		if(!mark_rev[revlist[u][i]])
			DFS_rev(revlist[u][i]);
	com[co].push_back(u);
}

int main()
{
	cin >> n >> m ;
	for(long long i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d" ,&x ,&y);
		x--;
		y--;
		mylist[x].push_back(y);
		revlist[y].push_back(x);
	}	
	for(int i = 0; i < n; i++)
		if(!mark[i])
			DFS(i);
	while(finish.size())
	{
		if(!mark_rev[finish.back()])
		{
			DFS_rev(finish.back());
			sort(com[co].begin(), com[co].end());
			checking.push_back(make_pair(com[co][0], co));
			co++;
		}
		finish.pop_back();
	}
	sort(checking.begin(), checking.end());
	cout << co << endl;
	for(int i = 0; i < checking.size(); i++)
	{
		cout << com[checking[i].second].size() << " ";
		for(int j = 0; j < com[checking[i].second].size(); j++)
			cout << com[checking[i].second][j] + 1 << " ";
		cout << endl;
	}
}
