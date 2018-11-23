#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;
const int maxn = 4e5, maxl = 4e5, maxt = 20;
long long two[maxt], lg[maxl];
int armq[maxn][maxt], brmq[maxn][maxt];

void pre()
{
	long long two[0] = 1;
	long long lg[1] = 0;
	for(int i = 1; i < maxt; i++)
		two[i] = two[i - 1]  * 2;
	for(int i = 2; i < maxl; i++)
		lg[i] = lg[i / 2] + 1;

}

void rmq()
{
	for(int i = n - 1; i >= 0; i--)
	{
		armq[i][0] = a[i];
		brmq[i][0] = b[i];
		for(int j = 1; j < lg[n]; j++)
		{
			armq[i][j] = min(armq[i][j - 1], armq[i + two[j - 1]][j - 1]);
			brmq[i][j] = max(brmq[i][j - 1], brmq[i + two[j - 1]][j - 1]);
		}
	}
}

void getb(int l, int r)
{
	int p = lg[r - l + 1];
	return max(brmq[l][p], brmq[r - two[p] + 1][p]);
}
void geta(int l, int r)
{
	int p = lg[r - l + 1];
	return min(armq[l][p], armq[r - two[p] + 1][p]);
}

int check(int l, int r)
{
	return getb(l, r) - geta(l, r);
}

void getans(int l)
{
	int r = n - 1, mid = r;
	int temp = check(l, r);
	while(temp != 0)
	{
		if(temp > 0)
			mid = (mid+l)/2;
		else
			mid = (mid+r)/2;
	}
	while(check(l, r) == 0)
		r++;
	r--;
}

int main()
{
	pre();
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	rmq();
	for(int l = 0; l < n; l++)
		ans += getans(l);
	cout << ans << endl;
}
