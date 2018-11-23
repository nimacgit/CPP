#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;


typedef pair<int,int> pii;
#define mp  make_pair 

const int maxn = 20 * 1000;
int n, t, maxvalue, maxi;
int d[maxn + 100];
vector <pii> a;

bool comp(pii fir, pii sec)
{
	return fir >= sec;
}


int lis()
{
	for(int i = 1; i < n; i++)
		d[i] = -1;
	d[1] = a[0].second;
	maxi = 1;
	for(int i = 1; i < n; i++)
	{
		int found = upper_bound(d + 1, d + maxi + 1, a[i].second) - d;
		//cout << found << " i= " << i << " maxi " << maxi << endl;
		d[found] = a[i].second;
		if(found > maxi)
			maxi++;
		//cout <<  " 1parenti " << parent[i] << endl;
		//parent[found + 1] = i;
	}
	return maxi;
}


int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		a.clear();
		for(int j = 0; j < n; j++)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			a.push_back(mp(temp1, temp2));
		}
		sort(a.begin(), a.end(), comp);
		//cerr << a[0].first << "  " << a[1].first << "  " << a[2].first << endl;
		cout << lis() << endl;
	}
	return 0;
}