#include <bits/stdc++.h>

using namespace std;


const int maxn = 1000*10 + 100;
int adj[maxn][maxn];
vector <int> matr[maxn];
queue <int> myque;
int n, m;
bool seen[maxn];

void push(int f){
	if(!seen[f])
		myque.push(f);
	seen[f] = true; 
}

void bfs(int f){
	push(f);
	while(!myque.empty()){
		int v = myque.front();
		for(int i = 0; i < matr[v].size(); i++)
			push(matr[v][i]);
		myque.pop();
	}
}






int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		matr[x].push_back(y);
		matr[y].push_back(x);
	}
	bfs(0);
	return 0;
}
