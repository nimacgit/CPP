#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

typedef pair<int,int> pii;
#define mp(x,y) make_pair(x, y) 

const int maxn = 5 * 1000 + 100;
bool seen[maxn];
vector <int> adj[maxn];
set <vector <int> > son;
int n;
set <pii> myset;


int DFS(int v)
{
	seen[v] = true;
	int vertex = 1;
	vector<int> tempson;
	for(int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if(!seen[u])
		{
			tempson.push_back(DFS(u));
			vertex += tempson.back();
		}
	}
	sort(tempson.begin(), tempson.end());
	if(tempson.size() > 0)
		son.insert(tempson);
	return vertex;
}

void proc()
{
	vector <int> child;
	for(int i = 0; i < son.begin()->size(); i++)
		child.push_back((*son.begin())[i]);
	int x = son.begin()->size();
	int have[x];
	fill(have, have + x, 0);
	int y = 0;
	for(int i = 0; i < x; i++)
	{
		if(i != 0)
		{
			if(((*son.begin())[i]) != ((*son.begin())[i - 1]))
				y++;
		}
		have[y]++;
	}
	y++;
	x = y;
	unique(child.begin(), child.end());
	//cerr << " work " << endl;
	int use[x];
	fill(use, use + x, 0);
	int sum = 0;
	while(use[x - 1] <= have[x - 1])
	{
		sum = 0;
		for(int i = 0; i < x; i++)
			sum +=  child[i] * use[i];
		//cerr << " sum " << sum << "  " << use[x - 1] << "  " << have[x - 1] << endl;
		if((sum > 0) && ((n - sum - 1) > 0))
		{
			myset.insert(mp(sum, n - sum - 1));
			myset.insert(mp(n - sum - 1, sum));
		}
		use[0]++;
		int i = 0;
		while(i < x - 1 && use[i] > have[i])
		{
			use[i] -= (have[i] + 1);
			use[i + 1]++;
			i++;
		}
	}
	/*cerr << " son " << sum << "  " <<  endl;
	for(int i = 0; i < son.begin()->size(); i++)
		cerr << (*son.begin())[i] << " ";
	cerr << endl;
	*/
	son.erase(son.begin());
}


int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		temp1--;
		temp2--;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	DFS(0);
	while(!son.empty())
		proc();	
	printf("%d \n", myset.size());
	while(!myset.empty())
	{
		printf("%d %d \n", myset.begin()->first, myset.begin()->second);
		myset.erase(myset.begin());
	}
	return 0;
}