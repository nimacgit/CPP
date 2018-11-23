#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> pie;
const int maxn = 200 * 1000;
int dol[maxn + 100];
int pon[maxn + 100];
int n, m, s, k;
vector<pie> gadd, gadp;
long long sd[maxn + 100];
long long sp[maxn + 100];
pie mini[maxn + 100];
int mindol, minpon;
int choosp, choosd;
//poss(day) : one base
bool poss(int day)
{
	for(int i = 0; i <= k; i++)
		if(i <= mindol && k - i <= minpon && (long long)sd[i] * dol[mini[day].F] + (long long)sp[k - i] * pon[mini[day].S] <= s)
		{
			choosd = i;
			choosp = k - i;
			return true;
		}
	return false;
}


int get(int start, int end)
{
	if(start == end)
		return start;
	int mid = (start + end)/2;
	if(poss(mid))
		return get(start, mid);
	return get(mid+1, end);

}


int main()
{
	cin >> n >> m >> k >> s;
	for(int i = 0; i < n; i++)
		scanf("%d", &dol[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &pon[i]);
	for(int i = 0; i < m; i++)
	{
		int temp, c;
		scanf("%d %d", &c, &temp);
		if(c == 1)
			gadd.push_back(mp(temp, i));
		else
			gadp.push_back(mp(temp, i));
	}
	sort(gadd.begin(), gadd.end());
	sort(gadp.begin(), gadp.end());
	sd[0] = 0;
	sp[0] = 0;
	mindol = gadd.size();
	mindol = min(mindol, k);
	minpon = gadp.size();
	minpon = min(minpon, k);
	for(int i = 1; i <= mindol; i++)
		sd[i] = sd[i - 1] + gadd[i - 1].F;	
	for(int i = 1; i <= minpon; i++)
		sp[i] = sp[i - 1] + gadp[i - 1].F;
	mini[1] = mp(0, 0);
	for(int i = 2; i <= n; i++)
	{
		if(dol[mini[i - 1].F] <= dol[i - 1])
			mini[i].F = mini[i - 1].F;
		else
			mini[i].F = i - 1;
		if(pon[mini[i - 1].S] <= pon[i - 1])
			mini[i].S = mini[i - 1].S;
		else
			mini[i].S = i - 1;
	}
	int pos = get(1, n);
	if(!poss(pos))
	{
		cout << -1 << endl;
		return 0;
	}
	cout << pos << endl;
	for(int i = 0; i < choosd; i++)
		cout << gadd[i].S + 1 << " " << mini[pos].F + 1 << endl;
	for(int i = 0; i < choosp; i++)
		cout << gadp[i].S + 1 << " " << mini[pos].S + 1 << endl;
}
