#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 2e6;
long long seen[maxn];
long long n, k;
vector<long long> mv;
long long lpos = 1;
long long num[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n;
	for(long long i = 0, temp; i < k; i++)
	{
		cin >> temp;
		if(temp <= k + 1)
			seen[temp]++;
		num[i] = temp;
	}
	while(seen[lpos] > 0)
		lpos++;
	seen[lpos]++;
	mv.push_back(lpos);
	for(int i = 0; i < k; i++)
	{
		if(num[i] <= k + 1)
			seen[num[i]]--;
		while(seen[lpos] > 0)
			lpos++;
		if(num[i] <= k+1 && seen[num[i]] == 0 && num[i] < lpos)
			mv.push_back(num[i]);
		else
		{
			seen[lpos]++;
			mv.push_back(lpos);
		}
	}
	long long x = (n-1) / k, y = (n-1) % k;
	long long pos = 0;
	pos += y;
	pos -= x;
	pos++;
	if(pos < 0)
		pos += ((-1ll*pos)/(k+1) + 10) * (k + 1);
	pos %= (k + 1);
	cout << mv[pos] << endl;
}
