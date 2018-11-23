#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;

const int maxn = 1000 * 100;
typedef pair<int, int> pie;
pie seg[4 * maxn + 1000];
int a[maxn + 100];
int n, q;

pie update(pie *temp)
{
	pie temp3 = pie(-1, -1);
	for(int i = 0; i < 2; i++)
	{
		if(temp3.x != -1)
		{
			if(temp[i].x != -1)
			{
				if(a[temp3.x] <= a[temp[i].x])
				{
					temp3.y = temp3.x;
					temp3.x = temp[i].x;
					if(temp[i].y != -1)
					{
						if(a[temp[i].y] > a[temp3.y])
							temp3.y = temp[i].y;
					}	
				}
				else
				{
					if(temp3.y != -1)
					{
						if(a[temp3.y] < a[temp[i].x])
							temp3.y = temp[i].x;
					}
					else
						temp3.y = temp[i].x;
				}
			}
		}
		else
		{
			if(temp[i].x != -1)
			{
				temp3.x = temp[i].x;
				if(temp[i].y != -1)
					temp3.y = temp[i].y;
			}
		}
	}
	return temp3;
}


pie setnum(int start, int end, int andis, int value, int segnum)
{
	if(start > andis || end < andis)
		return seg[segnum];
	else
	{
		if(start == end)
			return seg[segnum] = pie(start - 1, -1);
		int mid = (start + end)/2;
		pie temp[2];
		temp[0] = setnum(start, mid, andis, value, 2 * segnum), temp[1] = setnum(mid + 1, end, andis, value, segnum * 2 + 1);
		return seg[segnum] = update(temp);
	}
}

pie getsum(int start, int end, int s, int e, int segnum)
{
	if(start > e || end < s)
		return pie(-1, -1);
	if(end <= e && start >= s)
		return seg[segnum];
	int mid = (start + end)/2;
	pie temp[2];
	temp[0] = getsum(start, mid, s, e, 2 * segnum), temp[1] = getsum(mid + 1, end, s, e, segnum * 2 + 1);
	return update(temp);
}

pie naive(int k, int l)
{
	int max[2];
	max[0] = -1;
	max[1] = -1;
	for(int i = k - 1; i <= l - 1; i++)
	{
		if(max[0] == -1)
			max[0] = i;
		else
		{
			if(a[max[0]] <= a[i])
			{
				max[1] = max[0];
				max[0] = i;
			}
			else
			{
				if(max[1] == -1)
					max[1] = i;
				else
				{
					if(a[max[1]] < a[i])
						max[1] = i;
				}
			}
		}
	}
	return pie(max[0], max[1]);
}

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			pie temp[2];
			temp[0] = naive(i, j);
			temp[1] = getsum(1, n, i, j, 1);
			if(a[temp[0].x] + a[temp[0].y] !=  a[temp[1].x] + a[temp[1].y] )
			{
				cerr << " bug " << i << " " << j << endl;
				cerr << temp[0].x << " " << temp[0].y << endl;
				cerr << temp[1].x << " " << temp[1].y << endl;
				return false;
			}
		}
	cerr << "succ" << endl;
	return true;
}



int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		setnum(1, n, i + 1, a[i], 1);
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		char c;
		int k, l;
		scanf("%1s", &c);
		scanf("%d %d", &k, &l);
		if(c == 'U')
		{
			a[k - 1] = l;
			setnum(1, n, k, l, 1);
		}
		else
		{
			pie temp = getsum(1, n, k, l, 1);
			printf("%d\n", a[temp.x] + a[temp.y]);
		}
	}
	return 0;

}
