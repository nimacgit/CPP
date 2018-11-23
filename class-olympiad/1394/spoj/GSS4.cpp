#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define x first
#define mp make_pair
#define y second

using namespace std;

typedef pair<int, int> pie;
int n, q;
const int maxn = 1000 * 100;

long long seg[4 * maxn + 100];
int a[maxn + 100];
const int mininf = -1000 * 1000;


int getmax(const int &start, const int &end, const int &s, const int &e, const int &segnum)
{
	if(e < start || s > end)
		return 0;
	if(s <= start && end <= e)
		return seg[segnum];
	int mid = (start+end)/2;
	return getmax(start, mid, s, e, 2*segnum) + getmax(mid + 1, end, s, e, 2 * segnum + 1);
}

long long init(int start,int end,int s, int e, int segnum)
{
	if(s > end || e < start)
		return seg[segnum];
	if(start == end)
		return seg[segnum] = a[start-1];
	int mid = (start+end)/2;
	return seg[segnum] =  init(start, mid, s, e, 2 * segnum) + init(mid + 1, end, s, e, 2 * segnum + 1);
}
long long update(int start, int end, int s, int e, int segnum)
{
	if(start > e || end < start)
		return 0;
	if(start == end)
		return seg[segnum] = a[start - 1] = sqrt(a[start - 1]);
	int mid = (start + end)/2;
	return seg[segnum] = update(start, mid, s, e, 2 * segnum) + update(mid + 1, end, s, e, 2 * segnum + 1);
}
/*  
int naive(int i, int j)
{
	int t[2 * maxn + 100];
	for(int k = 0; k < 2 * maxn + 10; k++)
		t[k] = 0;
	for(int k = i; k <= j; k++)
		t[a[k - 1] + maxn]++;	
	int maxim = 1;
	for(int k = 0; k < 2 * maxn + 2; k++)
		if(t[k] > t[maxim])
			maxim = k;
	return t[maxim];

}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
			if(naive(i,j) != getmax(1, n,i, j, 1))
			{
				cerr << " uns " << naive(i,j) << " " << getmax(1, n, i, j, 1) << " ";
				cout << i << " " << j << endl;
				return false;
			}
	}
	cerr << "succuss" << endl;
	return true;
}
*/
int main()
{
	ios::sync_with_stdio();
	while(scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			a[i] *= a[i];
		}
		init(1, n, 1, n, 1);
		scanf("%d", &q);
		for(int i = 0; i < q; i++)
		{
			if(i % 1000 == 0)
			cerr << i << endl;
			int temp1, temp2, seti;
			scanf("%d %d %d", &seti, &temp1, &temp2);
			if(temp2 < temp1)
				swap(temp1, temp2);
			if(seti == 1)
				printf("%d\n", getmax(1, n, temp1, temp2, 1));
			else
				update(1, n, temp1, temp2, 1);
		}
		printf("\n");
	}
}

