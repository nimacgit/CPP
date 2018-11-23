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

struct nima
{
	int all, left, right, sum;
	nima(int a, int b, int c, int d)
	{
		all = a;
		left = b;
		right = c;
		sum = d;
	}
	nima()
	{

	};

};


nima seg[4 * maxn + 100];
int a[maxn + 100];
const int mininf = -1000 * 1000;


nima update(nima *temp)
{
	nima temp3;
	int maxi = mininf + 1;
	maxi = max(maxi, temp3.right = max(temp[1].sum + temp[0].right, temp[1].right));
	maxi = max(maxi, temp3.left = max(temp[0].sum + temp[1].left, temp[0].left));
	maxi = max(maxi, temp3.sum = temp[0].sum + temp[1].sum);
	temp3.all = max(maxi, max(temp[0].all, max(temp[1].all, temp[0].right + temp[1].left)));
	return temp3;
}

nima getmax(const int &start, const int &end, const int &s, const int &e, const int &segnum)
{
	if(e < start || s > end)
		return nima(mininf, mininf, mininf, mininf);
	if(s <= start && end <= e)
		return seg[segnum];
	nima temp[2];
	int mid = (start+end)/2;
	temp[0] = getmax(start, mid, s, e, 2 * segnum);
	temp[1] = getmax(mid + 1, end, s, e, 2 * segnum + 1);
	return update(temp);
}

nima init(const int &start,const int &end, const int &segnum)
{
	if(start == end)
		return seg[segnum] = nima(a[start-1], a[start-1], a[start-1], a[start-1]);
	nima temp[2];
	int mid = (start+end)/2;
	temp[0] = init(start, mid, 2 * segnum);
	temp[1] = init(mid + 1, end, 2 * segnum + 1);
	return seg[segnum] =  update(temp);
}

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
			if(naive(i,j) != getmax(1, n,i, j, 1).all)
			{
				cerr << " uns " << naive(i,j) << " " << getmax(1, n, i, j, 1).all << " ";
				cout << i << " " << j << endl;
				return false;
			}
	}
	cerr << "succuss" << endl;
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	init(1, n, 1);
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		printf("%d\n", getmax(1, n, temp1, temp2, 1).all);
	}
	return 0;
}

