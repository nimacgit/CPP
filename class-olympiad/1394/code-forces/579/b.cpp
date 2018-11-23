#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair 

const int maxn = 400;
set <pii> myset[maxn + 10];
int n;
bool use[maxn + 10];
int who[maxn + 10];

void find(int v)
{
	use[v] = true;
	bool ok = false;
	while(!ok)
	{
		cerr << " v " << v << endl;
		while(use[myset[v].begin()->second] && !myset[v].empty())
			myset[v].erase(myset[v].begin());
		if(!myset[v].empty())
		{
			int u = myset[v].begin()->second;
			while(myset[u].begin()->second != v && use[myset[u].begin()->second] && !myset[u].empty() )
				myset[u].erase(myset[u].begin());
			if(!myset[u].empty())
			{
				if(myset[u].begin()->second == v)
					ok = true;
				else
					find(myset[u].begin()->second);
			}
		}
	}
	int i = myset[v].begin()->second;
	use[i] = true;
	who[i] = v;
	who[v] = i;
}

int main()
{
	cin >> n;
	for(int i = 1; i < 2 * n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			int temp;
			cin >> temp;
			myset[i].insert(mp(-1 * temp, j));
		}
	}
	find(1);
	for(int i = 0; i < 2 * n; i++)
		cout << who[i] + 1 << " ";
	cout << endl;
}