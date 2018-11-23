#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;


const int maxn = 200;
int d[maxn + 10];
vector<int> parents;
const int inf = 1 << 30 - 1;


void dfs(int v)
{
	//cout << v << endl;
	if(parents.size() <= d[v])
	{
		d[v] = parents.size();
		parents.push_back(v);
		for(int i = parents.size() - 1; i >= 0; i--)
			if(v + parents[i] <= maxn)
				dfs(v + parents[i]);
		parents.pop_back();
	}
}



int main()
{
	for(int i = 0; i <= maxn; i++)
		d[i] = inf;
	dfs(1);
	long long sum = 0;
	for(int i = 2; i <= maxn; i++)
		sum += d[i];
	cout << sum << endl;
}

