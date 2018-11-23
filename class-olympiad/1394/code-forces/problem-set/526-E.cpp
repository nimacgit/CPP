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

const int maxn = 1000 * 1000 + 100;
int n, q, minn;
long long d;
int a[maxn], nexti[maxn];


void findnext()
{
	cerr << "findnext " << endl;
	minn = 0;
	long long sum = a[0];
	int j = 1;
	while(sum + a[j] <= d)
	{
		sum += a[j];
		j++;
	}
	nexti[0] = j - 1;
	for(int i = 1; i < n; i++)
	{
		int fj = j;
		sum -= a[i - 1];
		while(sum + a[j] <= d)
		{
			sum += a[j];
			j = (j+1)%n;
		}
		if(j < fj)
			nexti[i] =  n - fj + j + nexti[i - 1] - 1;
		else
			nexti[i] = j - fj + nexti[i - 1] - 1;
		if(nexti[i] < nexti[minn])
			minn = i;
	}
}


int check(int start)
{
	cerr << " check " << endl;
	int cnt = 0, i = start;
	while(i >= start && i + nexti[i] + 1 < n)
	{
		cnt++;
		i = i + nexti[i] + 1;
	}
	cnt++;
	i = (i + nexti[i] + 1) % n;
	while(i < start && i + nexti[i] + 1 < n)
	{
		cnt++;
		i = i + nexti[i] + 1;
	}
	return cnt;

}

int getans()
{
	cerr << " ans " << endl;
	int ans = 1e9;
	for(int i = 0; i <= nexti[i] + 1; i++)
	{
		cerr << " i " << i << "  " << check(minn + i) << endl;
		ans = min(ans, check(minn + i));
	}
	return ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < q; i++)
	{
		cin >> d;
		findnext();
		cout << getans() << endl;
	}
}
