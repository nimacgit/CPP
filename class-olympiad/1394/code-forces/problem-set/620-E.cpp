#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
using namespace std;

typedef pair<long long, long long> pie;
const int maxn = 400 * 1000 + 9;
long long seg[4 * maxn];
long long all[4 * maxn];
int posvert[maxn], col[maxn], nsize[maxn], vert[maxn];
bool seen[maxn];
vector<int> adj[maxn];
int co = 0;
long long maxtwo = ((long long)1<<62) - (long long)1;
int n, m;

int dfs(int v)
{
	posvert[v] = co;
	vert[co] = v;
	co++;
	int temp = 0;
	seen[v] = true;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
			temp += dfs(u);
	}
	nsize[v] = temp;
	return temp + 1;
}

long long make(int start, int end, int segnum)
{
	all[segnum] = 0;
	if(end == start)
		return seg[segnum] = ((long long)1 << col[vert[start - 1]]);
	int mid = (start + end) / 2;
	return seg[segnum] = (make(start, mid, 2 * segnum) | make(mid + 1, end, 2 * segnum + 1));
}

long long get(int start, int end, int s, int e, int segnum)
{
	if(start >= s && end <= e)
		return seg[segnum];
	if(start > e || end < s)
		return 0;
	int mid = (start + end)/2;
	if(all[segnum] == 0)
		return (get(start, mid, s, e, 2 * segnum) | get(mid + 1, end, s, e, 2*segnum + 1));
	return all[segnum];
}

void update(int start, int end, int s, int e, int c, int segnum)
{
//	cerr << " start " << start << " end " << end << " s " << s << " e " << e << " c " << c << " seg " << segnum << endl;
	if(start >= s && end <= e)
	{
		all[segnum] = ((long long)1 << c);
	//	cerr << "check sig " << all[segnum] << endl;
		seg[segnum] = all[segnum];
		return;
	}
	if(start > e || end < s)
		return;
	int mid = (start + end)/2;
	if(all[segnum] != 0)
	{
	//	cerr << " check log " << log2(all[segnum]) << " " << all[segnum] << endl;
		update(start, mid, start, mid, log2(all[segnum]),2*segnum);
		update(mid + 1, end, mid + 1, end, log2(all[segnum]), 2*segnum + 1);
		all[segnum] = 0;
	}
	update(start, mid, s, e, c, 2*segnum);
	update(mid + 1, end, s, e, c, 2*segnum + 1);	
	seg[segnum] = (get(start, mid, start, mid, 2*segnum) | get(mid + 1, end, mid + 1, end, 2*segnum + 1));
	//cerr << " new seg " << seg[segnum] << " start " << start << " end " << end << " s " << s << " e " << e << " seg " << segnum << endl;
}



int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &col[i]);
		col[i]--;
	}		
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0);
	make(1, n, 1);
	for(int i = 0; i < m; i++)
	{
		int ki;
		scanf("%d", &ki);
		if(ki == 1)
		{
			int ve, cole;
			scanf("%d %d", &ve, &cole);
			ve--;
			cole--;
			update(1, n, posvert[ve] + 1, posvert[ve] + 1 + nsize[ve], cole, 1);
//			cerr << " colering " << cole << " " << ve << endl;
//			for(int i = 0; i < n; i++)
//				for(int j = i; j < n; j++)
//					cerr << " i j " << i << " " << j << " get " << get(1, n, i + 1, j + 1, 1) << endl;
	
		}
		else
		{
			int ve;
			scanf("%d", &ve);
			ve--;
//			cerr << " nsize " << nsize[ve] << "  posvert  " << posvert[ve] << endl;
			long long anst = get(1, n, posvert[ve] + 1, posvert[ve] + 1 + nsize[ve], 1);
//			cerr << " anst " << anst << endl;
			printf("%d\n",  __builtin_popcountll(anst));

		}
	}
}
