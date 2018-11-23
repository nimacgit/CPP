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
long long sum, n, t;
const int maxn = 1000 * 100;
int a[maxn + 100];


void merg(int s, int m, int e)
{
	int * a1 = new int[e - s + 1];
	int start = s, mid = m + 1, pos = 0;
	while(pos < e - s + 1)
	{
		if(start > m)
		{
			a1[pos] = a[mid];
			mid++;
		}
		else
		{

			if(mid > e)
			{
				a1[pos] = a[start];
				start++;
			}
			else
			{
				if(a[start] == a[mid])
				{
					a1[pos] = a[start];
					start++;
				}
				else
				{
					if(a[start] > a[mid])
					{
						a1[pos] = a[mid];
						sum += m - start + 1;
						mid++;
					}
					else
					{
						a1[pos] = a[start];
						start++;
					}
				}

			}
		}
		pos++;

	}
	for(int i = s; i <= e; i++)
	{
		a[i] = a1[i - s];
	}
}

void findmin(int start, int end)
{
	if(start == end)
		return;
	else
	{
		int mid = (start + end) / 2;
		findmin(start, mid);
		findmin(mid + 1, end);
		merg(start, mid, end);
	}
}




int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		for(int j = 0; j < n; j++)
			scanf("%d", &a[j]);
		sum = 0;
		findmin(0, n - 1);
		cout << sum << endl;
	}
}
