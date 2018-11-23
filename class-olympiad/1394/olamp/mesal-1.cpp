#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
vector<int> adj[maxn], tadj[maxn];
bool seen[maxn], tseen[max];
vector<int> top;


void dfs(int v, vector<int> *adj, bool *seen, bool f)
{
	seen[v] = true;
	for(auto u : adj[v])
		if(!seen[i])
			dfs(u, adj, seen, f);
	if(f)
		top.push_back(v);
}




int main()
{

}
