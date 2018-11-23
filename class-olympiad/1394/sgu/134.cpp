#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#define mp make_pair


using namespace std;

typedef pair<int, int> pii;
const int maxn = 16 * 1000;
int par[maxn + 100], sum[maxn + 100];
vector <int> sons[maxn + 100];
vector<int>  matr[maxn + 100];
int minim;
bool seen[maxn + 100];
bool isminim[maxn + 100];
set <pii> myset;
int n;

void dfs(int v)
{
	seen[v] = true;
	sum[v] = 0;
	for(int i = 0; i < matr[v].size(); i++)
	{
		int u = matr[v][i];
		if(!seen[u])
		{
			par[u] = v;
			sons[v].push_back(u);
			dfs(u);
			sum[v] += sum[u] + 1;
		}

	}
	par[v] = n - 1 - sum[v];
}

void find(int v)
{
	int mini = par[v];
	for(int i = 0; i < sons[v].size(); i++)
		mini = max(mini, sum[sons[v][i]] + 1);
	myset.insert(mp(mini, v));
}


int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		matr[x].push_back(y);
		matr[y].push_back(x);
	}
	par[0] = 0;
	dfs(0);
	for(int i = 0; i < n; i++)
		find(i);
	minim = myset.begin()->first;
	int co = 0;
	while(myset.begin()->first == minim)
	{
		isminim[myset.begin()->second] = true;
		myset.erase(myset.begin());
		co++;
	}
	cout << minim << " " << co << endl;
	for(int i = 0; i < n; i++)
		if(isminim[i])
			cout << i + 1 << " ";
	cout << endl;
}

