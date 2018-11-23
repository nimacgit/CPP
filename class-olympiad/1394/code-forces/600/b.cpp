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


const int maxn = 2000 * 100;
pie b[maxn + 1000];
int n, m;
int d[maxn + 1000], a[maxn + 1000];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%d" , &a[i]);
	for(int i = 0; i < m; i++)
	{
		int x;
		scanf("%d" , &x);
		b[i] = mp(x, i);
	}
	sort(a, a + n);
	sort(b, b + m);
	int k = 0;
	for(int i = 0 ; i < m; i++)
	{
		while(k < n && a[k] <= b[i].first)
			k++;
		d[b[i].second] = k;
	}
	for(int i = 0; i < m; i++)
		cout << d[i] << " ";
	cout << endl;

}	
