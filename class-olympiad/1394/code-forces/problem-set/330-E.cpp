/*
 * =====================================================================================
 *
 *       Filename:  330-E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۳ ۰۱:۰۰:۰۹
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> pie;

const int maxn = 1000 * 100;
pie adj[maxn + 100];
vector<pie> mad;
bool seen[maxn + 100];
vector<int> comp[maxn + 100];
int remain = 0;
int n, m;
int co = 0;
bool circ[maxn + 100];
int deg[maxn + 100];
vector <pie> save;


bool dfs(int s, int comnum, int se)
{
	bool flag1 = false, flag2 = false;
	seen[s] = true;
	if(adj[s].x != -1)
	{
		flag1 = true;
		if(!seen[adj[s].x])
			flag1 &= dfs(adj[s].x, comnum, 1);
	}
	if(se == 0)
		comp[comnum].push_back(s);
	if(adj[s].y != -1)
	{
		flag2= true;
		if(!seen[adj[s].y])
			flag2 &= dfs(adj[s].y, comnum, 1);
	}
	if(se != 0)
		comp[comnum].push_back(s);
	return flag1 & flag2;
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		adj[i] = mp(-1, -1);
	for(int i = 0; i < m; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		temp1--;
		temp2--;
		if(adj[temp1].x != -1)
			adj[temp1].y = temp2;
		else
			adj[temp1].x = temp2;
		if(adj[temp2].x != -1)
			adj[temp2].y = temp1;
		else
			adj[temp2].x = temp1;
	}
	for(int i = 0; i < n; i++)
		if(!seen[i])
		{
			circ[co] = dfs(i, co, 0);
			co++;
			cerr << " circ " << co-1 << " " << circ[co-1] << endl;
		}
	for(int i = 0; i < co; i++)
	{
		if(circ[i])
		{
			if(comp[i].size() == 3)
			{
				remain+=3;
			}
			else if(comp[i].size() == 4)
			{
				mad.push_back(mp(comp[i][0], comp[i][2]));
				deg[comp[i][0]]++;
				deg[comp[i][2]]++;
				mad.push_back(mp(comp[i][1], comp[i][3]));
				deg[comp[i][1]]++;
				deg[comp[i][3]]++;
				remain+=2;
			}
			else
				for(int j = 0; j < comp[i].size(); j++)
				{
					deg[comp[i][(j+2)%(comp[i].size())]]++;
					deg[comp[i][j]]++;
					mad.push_back(mp(comp[i][j], comp[i][(j + 2)%(comp[i].size())]));
				}
		}
		else
		{
			if(comp[i].size() == 2)
			{
				remain++;
			}
			else if(comp[i].size() == 3)
			{
				remain++;
				deg[comp[i][0]]++;
				deg[comp[i][2]]++;
				mad.push_back(mp(comp[i][0], comp[i][2]));
			}
			else if(comp[i].size() > 3)
			{
				for(int j = 0; j < comp[i].size() - 2; j++)
				{
					deg[comp[i][j]]++;
					deg[comp[i][j+2]]++;
					mad.push_back(mp(comp[i][j], comp[i][j + 2]));
				}
				if(comp[i].size() % 2 == 0)
				{
					mad.push_back(mp(comp[i][comp[i].size() - 1], comp[i][0]));
					deg[comp[i][0]]++;
					deg[comp[i][comp[i].size() - 1]]++;
					save.push_back(mp(comp[i][comp[i].size() - 2], comp[i][1]));
					deg[comp[i][comp[i].size() - 2]]++;
					deg[comp[i][1]]++;
				}
				else
				{
					mad.push_back(mp(comp[i][comp[i].size() - 1], comp[i][1]));
					deg[comp[i][1]]++;
					deg[comp[i][comp[i].size() - 1]]++;
					save.push_back(mp(comp[i][comp[i].size() - 2], comp[i][0]));
					deg[comp[i][comp[i].size() - 2]]++;
					deg[comp[i][0]]++;
				}
			}
		}
	}
	while(remain > 0 && !save.empty())
	{
		mad.push_back(save[save.size() - 1]);
		save.pop_back();
	}
	for(int i = 0; i < co && remain > 0; i++)
	{
		cerr << i << " "  << remain << endl;
		for(int j = i + 1; j < co && remain > 0; j++)
		{
			for(int k = 0; k < comp[i].size() && remain > 0; k++)
			{
				for(int l = 0; l < comp[j].size() && remain > 0; l++)
				{
					if(deg[comp[i][k]] < 2)
					{
						if(deg[comp[j][l]] < 2)
						{
	
							deg[comp[i][k]]++;
							deg[comp[j][l]]++;
							mad.push_back(mp(comp[i][k], comp[j][l]));
							remain--;
						}
						else
						{
							swap(comp[j][l], comp[j][comp[j].size() - 1]);
							comp[j].pop_back();
							l--;
						}
					}
					else
					{
						swap(comp[i][k], comp[i][comp[i].size() - 1]);
						comp[i].pop_back();
						l = 0;
					}
				}
			}
		}
	}
	cerr << remain << endl;
	if(remain > 0)
		cout << -1 << endl;
	else
		for(int i = 0; i < mad.size(); i++)
			cout << mad[i].x + 1 << " " << mad[i].y + 1 << endl;

}
