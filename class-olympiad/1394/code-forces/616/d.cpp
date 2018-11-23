#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn =  5 * 100 * 1000;
set <pie> myset;
set <pie>::iterator it;
int n, k, dif, len = 0, mlen = 0, pos = 0;
int a[maxn + 100];

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		it = myset.lower_bound(mp(a[i],0));
		if(it != myset.end() && it->first == a[i])
		{
			pie k = *it;
			k.second++;
			myset.erase(it);
			myset.insert(k);
		}
		else
		{
			myset.insert(mp(a[i], 1));
			dif++;
		}
		len++;
		while(dif > k)
		{
			it = myset.lower_bound(mp(a[i - len + 1], 0));
			pie k = *it;
			k.second--;
			len--;
			myset.erase(it);
			if(k.second != 0)
				myset.insert(k);
			else
				dif--;
		}
		if(mlen < len)
		{
			pos = i;
			mlen = len;
		}
	}
	cout << pos - mlen + 2 << " " << pos + 1 << endl;




}
