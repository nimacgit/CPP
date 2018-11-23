#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#define mp make_pair
using namespace std;

typedef pair<long long,long long> pll;
long long x1, x2;
vector<pll> dis;
int n;

int main()
{
	cin >> n;
	cin >> x1 >> x2;
	for(int i = 0; i < n; i++)
	{
		int t, t1;
		scanf("%d %d", &t, &t1);
		long long k = t, b = t1;
		dis.push_back(mp((long long)k * x1 + b,(long long)k * x2 + b));
	}
	sort(dis.begin(), dis.end());
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; dis[j - 1].first == dis[i].first &&  j < n; j++)
			if(dis[i].second > dis[j].first && dis[j].second != dis[i].first && dis[i].second > dis[j].second)
			{
				cout << "YES" << endl;
				return 0;
			}
	}
	cout << "NO" << endl;
	return 0;
	


	
}
