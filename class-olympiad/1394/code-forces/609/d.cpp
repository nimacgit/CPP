#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, pair<int,int> > pie;
const int maxn =  2 * 1000 * 100;

int n, m, k, s, mind, minp;
vector<int> gad[2];
int dol[maxn + 100], pon[maxn + 100];
int mini[maxn + 100][2];
vector<pie> minipay;
int day[maxn + 100];
int en, start = 0;

bool comp(int s, int z)
{
	return true;
}


int main()
{
	cin >> n >> k >> m >> s;
	for(int i = 0; i < n; i++)
	{
		day[i] = i;
		scanf("%d", &dol[i]);
		if(i == 0)
			mind = 0;
		if(dol[i] < dol[mind])
			mind = i;
		mini[i][0] = mind;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &pon[i]);
		if(i == 0)
			minp = 0;
		if(pon[i] < pon[minp])
			minp = i;
		mini[i][1] = minp;
	}
	for(int i = 0; i < m; i++)
	{
		int temp, temp1;
		scanf("%d %d", &temp, &temp1);
		temp--;
		gad[temp].push_back(temp1);
	}
	sort(gad[0].begin(), gad[0].end());
	sort(gad[1].begin(), gad[1].end());
	en = k;
	if(gad[0].size() < k)
		en = gad[0].size();
	if(gad[1].size() < k)
		start = k - gad[1].size();
	int sumd = 0, sump = 0;
	for(int i = 0; i < k - en; i++)
		sump += gad[1][i];
	for(int i = 0; i < start; i++)
		sumd += gad[0][i];
	minipay.push_back(mp(sumd, sump));
	for(int i = start; i < en; i++)
	{
		sumd += gad[0][i];
		sump -= gad[1][k - i];
		minipay.push_back(mp(sumd, sump));
	}
	int s = 0, e = n;
	int pos = lower_bound(0, n, 2, comp);

}
