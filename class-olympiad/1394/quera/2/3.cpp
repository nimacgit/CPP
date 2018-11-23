#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e5;
map<int, int> m;
int n, k, dif = 0;
int a[maxn];
map<int ,int>::iterator it;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]] = 0;
	}
	int start = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int temp = a[i];
		cerr << " what the " << endl;
		for(it = m.begin(); it != m.end(); it++)
			cerr << it->F << " " << it->S << endl;
		cerr << "gin" << endl;
		if(m[temp] == 0)
		{
			if(k == dif - 1)
			{
				it = m.end();
				it--;
				ans = max(ans, it->S);
				while(dif == k + 1)
				{
					if(m[a[start]] == 1)
						dif--;
					m[a[start]]--;
					start++;
				}
			}
			dif++;
		}
		m[temp]++;
	}
	cout << ans << endl;
}
