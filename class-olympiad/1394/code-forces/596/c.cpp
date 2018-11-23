#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 100 * 1000;
int w[2*maxn + 100];
pie p[maxn + 100];
int n;
vector<pie> dif;
int we[2*maxn + 100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, x, y; i < n; i++)
	{
		cin >> x >> y;
		p[i] = mp(x, y);
		w[y - x + maxn]++;
		dif.push_back(mp(y-x+maxn, i));
	}
	for(int i = 0, wb; i < n; i++)
	{
		cin >> wb;
		we[i] = wb;
		w[wb + maxn]--;
		if(w[wb + maxn] < 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	sort(we, we + n);
	sort(dif.begin(), dif.end());



}
