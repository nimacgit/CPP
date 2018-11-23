#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
vector<long long> sq;
const int maxn = 64000000;
long long sum[maxn + 100];
int co = 0;

bool isoky(long long a, int s, int e)
{
	if(e - s <= 1)
		return (sq[s] * sq[s] == a);
	int mid = (s + e)/2;
	if(sq[mid] * sq[mid] > a)
		return isoky(a, s, mid);
	return isoky(a, mid, e);
}
bool isok(long long a)
{
	return ((long long)sqrt(a) == (long double)(sqrt(a)));
}

int main()
{
	long long mx = 0;
	for(long long i = 1; i < maxn; i++)
	{
		sq.push_back((long long)i * i);
		for(int j = 1; j * i < maxn; j++)
			sum[i * j] += i * i;
	}
	for(int i = 1; i < maxn; i++)
		if(isoky(sum[i], 0, sq.size() - 1))
			co++;
	for(int i = 0; i < maxn; i++)
		cout << i << " " << sum[i] << endl;
	cout << co << endl;
}
