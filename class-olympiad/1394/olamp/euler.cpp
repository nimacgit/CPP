/*
 * =====================================================================================
 *
 *       Filename:  euler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۱۰ ۱۵:۱۶:۳۹
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

pie ed[maxn + 100];
vector<pie> adj[maxn + 100];
vector<int> myque;
bool mark[maxn + 100];
int n[maxn + 100] =lp


int other(const pie & a, const int & b){	return (a.first==b) ? a.second : a.first ; } 

struct edge
{
	int start, end, d;

	int other(int u){
		if(u==start)
			return end;
		return start ; 
	}
};

dfs(int s, int u)
{
	mark[s] = true;
	int v = other(ed[s], u);
	for(n[v]; n[v] < adj[v].size(); n[v]++)
	{
		int e = adj[v][n[v]].second;
		if(!mark[e])
		{
			dfs(e, v);
		}
	}
	myque.push_back(u);
}

void dfs(int v){
	for(n[v];n[v]<adj[v].size();n[v]++)
		if( !mark[e[v][n[v]].second] ) {
			mark[e[v][n[v]].second] = true; 
			dfs(e[v][n[v]].first]) ; 
		}
	myque.push-back(v);
}
