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
const int maxn = 1000 * 1000;
int n , m;
int a[maxn];
int seg[4 * maxn];

int mad(int start, int end, int segnum)
{
	if(start == end)
		return seg[segnum] = a[start - 1];
	int mid = (start+end)/2;
	mad(start, mid, 2 * segnum);
	mad(mid + 1, end, 2 * segnum + 1);
	if(seg[2*segnum] == seg[2*segnum + 1])
		return seg[segnum] = seg[2*segnum];
	return seg[segnum] = -1;
}

int find(int start, int end, int s, int e, int num, int segnum)
{
	if(start > e || end < s)
		return -1;
	if(start == end)
	{
		if(a[start - 1] == num)
			return -1;
		return start;
	}
	int mid = (start+end)/2;
	if(seg[segnum] == num)
		return -1;
	if(start >= s && end <= e)
		if(seg[segnum] != num && seg[segnum] != -1)
			return start;
	int fo = find(start, mid, s, e, num, 2 * segnum);
	if(fo == -1)
		return find(mid + 1, end, s , e, num , 2 * segnum + 1);
	return fo;

}


int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mad(1, n, 1);
	for(int i = 0; i < m; i++)
	{
		int x, l ,r;
		scanf("%d %d %d", &l, &r, &x);
		printf("%d\n", find(1, n, l, r, x, 1)); 
	}

}
