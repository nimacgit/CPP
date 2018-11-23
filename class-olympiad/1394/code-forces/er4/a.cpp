#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

const int maxn = 1e6;
int arr[maxn];
int n;
long long ans = 0;

void inv(int start, int end)
{
	int a[end - start + 10];
	if(end - start <= 1)
		return;
	int mid = (start + end) / 2;
	inv(start, mid), inv(mid, end);
	int l1 = start, l2 = mid;
	for(int i = start; i < end; i++)
	{
		if(l1 == mid)
		{
			a[i - start] = arr[l2];
			l2++;
		}
		else if(l2 == end)
		{
			a[i - start] = arr[l1];
			l1++;
		}
		else
		{
			if(arr[l2] < arr[l1])
			{
				a[i - start] = arr[l2];
				ans += mid - l1;
				l2++;
			}
			else
			{
				a[i - start] = arr[l1];
				l1++;
			}
		}
	}
	for(int i = start; i < end; i++)
		arr[i] = a[i - start];
}



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	inv(0, n);
	cout << ans << endl;
}

