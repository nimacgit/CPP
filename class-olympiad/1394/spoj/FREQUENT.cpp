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
	int all;
	pie left, right;
	nima(int a, pie b, pie c)
	{
		all = a;
		left = b;
		right = c;
	}
	nima()
	{

	};

};


nima seg[4 * maxn + 100];
int a[maxn + 100];


nima getmax(int start, int end, int s, int e, int segnum)
{
	if(e < start || s > end)
		return nima(-1, mp(-1,-1), mp(-1,-1));
	if(s <= start && end <= e)
		return seg[segnum];
	nima temp1, temp2;
	int mid = (start+end)/2;
	temp1 = getmax(start, mid, s, e, 2 * segnum);
	temp2 = getmax(mid + 1, end, s, e, 2 * segnum + 1);
	if(temp1.all != -1 && temp2.all != -1)
	{
		nima temp3;
		int maxi = 0;
		if(temp1.left.y == temp2.left.y)
		{
			temp3.left = temp1.left;
			temp3.left.x += temp2.left.x;
			maxi = temp3.left.x;
		}
		else
			temp3.left = temp1.left;
		if(temp1.right.y == temp2.right.y)
		{
			temp3.right = temp1.right;
			temp3.right.x += temp2.right.x;
			maxi = max(maxi,temp3.right.x);
		}
		else
			temp3.right = temp2.right;
		if(temp1.right.y == temp2.left.y)
			maxi = max(maxi, temp1.right.x + temp2.left.x);
		temp3.all = max(max(maxi, temp1.all), temp2.all);
		return temp3;
	}
	if(temp1.all != -1)
		return temp1;	
	return temp2;
}

nima init(int start, int end, int segnum)
{
	if(start == end)
	{
		seg[segnum] = nima(1, mp(1, a[start-1]), mp(1, a[start-1]));
		return seg[segnum];
	}
	else
	{
		nima temp1, temp2;
		int mid = (start+end)/2;
		temp1 = init(start, mid, 2 * segnum);
		temp2 = init(mid + 1, end, 2 * segnum + 1);
		nima temp3;
		int maxi = 0;
		if(temp1.left.y == temp2.left.y)
		{
			temp3.left = temp1.left;
			temp3.left.x += temp2.left.x;
			maxi = temp3.left.x;
		}
		else
			temp3.left = temp1.left;
		if(temp1.right.y == temp2.right.y)
		{
			temp3.right = temp1.right;
			temp3.right.x += temp2.right.x;
			maxi = max(maxi,temp3.right.x);
		}
		else
			temp3.right = temp2.right;
		if(temp1.right.y == temp2.left.y)
			maxi = max(maxi, temp1.right.x + temp2.left.x);
		temp3.all = max(max(maxi, temp1.all), temp2.all);
		return seg[segnum] = temp3;
	}
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
//	cout << "succuss" << endl;
	return true;
}

int main()
{
/*	srand(time(NULL));
	for(int i = 0; i < 1000; i++)
	{
		cout << i << endl;
		n = rand() % 100 + 1;
		vector<int> tester;
		tester.clear();
		for(int j = 0; j < n; j++)
			tester.push_back(rand() % 2*maxn - maxn);
		sort(tester.begin(), tester.end());
		cerr << "ok" << endl;
		for(int j = 0; j < n; j++)
			a[j] = tester[j];
		cerr << " ko " << endl;
		init(1, n, 1);
		cerr << "bow" << endl;
		if(!check())
		{
			for(int j = 0; j < n; j++)
				cout << tester[j] << " ";
			cout << endl;
			return 0;
		}
	}
*/	
	cin >> n;
	while(n != 0)
	{
		scanf("%d", &q);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		init(1, n, 1);
		for(int i = 0; i < q; i++)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			printf("%d\n", getmax(1, n, temp1, temp2, 1).all);
		}
		scanf("%d", &n);
	}

}

