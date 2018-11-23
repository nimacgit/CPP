/*
 * =====================================================================================
 *
 *       Filename:  272-E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۶ ۰۰:۰۵:۲۳
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>
#define mp make_pair


using namespace std;
typedef pair<int, int> pie;

const int maxn = 1000 * 1000;
int n, m;
vector<int> adj[maxn];
set<int> mys; 
int deg[maxn];
int where[maxn];
deque<int> myv;


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		temp1--;
		temp2--;
		adj[temp2].push_back(temp1);
		adj[temp1].push_back(temp2);
		deg[temp1]++;
		deg[temp2]++;
	}
	for(int i = 0; i < n; i++)
	{
		where[i] = 0;
		if(deg[i] > 1)
			myv.push_back(i);
	}
	while(!myv.empty())
	{
		int v = myv.front();
		if(deg[v] > 1)
		{
			if(where[v] == 0)
				where[v] = 1;
			else
				where[v] = 0;
			deg[v] = 0;
			for(int i = 0; i < adj[v].size(); i++)
			{
				int u = adj[v][i];
				if(where[v] == where[u])
				{
					deg[u]++;
					deg[v]++;
					if(deg[u] > 1)
						myv.push_back(u);
				}
				else
				{
					deg[u]--;
				}
			}
		}
		myv.pop_front();
	}
	for(int i = 0; i < n; i++)
		printf("%d", where[i]);
	cout << endl;
}
