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


const int maxn = 1000 * 100;
int f[maxn + 100];
bool isset[maxn + 100];
int b[maxn + 100], a[maxn + 100], d[maxn + 100];
int n, m;
bool am;
bool dob[maxn + 100];

bool comp(pie a, pie b)
{
	return a.first < b.first;
}






int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		f[temp] = i;
		if(isset[temp])
			dob[temp] = true;
		isset[temp] = true;
	}
	for(int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	for(int i = 0; i < m; i++)
	{
		if(!isset[b[i]])
		{
			cout << "Impossible" << endl;
			return 0;
		}
		if(dob[b[i]])
			am = true;
		a[i] = f[b[i]];
	}
	if(am)
		cout << "Ambiguity" << endl;
	else
	{
		cout << "Possible" << endl;
		for(int i = 0; i < m; i++)
			cout << a[i] + 1 << " ";
		cout << endl;
	}
}
