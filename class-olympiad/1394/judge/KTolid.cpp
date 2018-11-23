#include <iostream>
#include <stdio.h>

using namespace std;

const long long maxn = 2 * 1000 * 100 + 3;
long long d[2][2];
long long n;
long long cost1[maxn];
long long cost2[maxn];
long long change12[maxn];
long long change21[maxn];

void findcost()
{
	d[0][1] = cost1[1];
	d[1][1] = cost2[1];
	for(long long i = 2; i <= n; i++)
	{
		d[0][i % 2] = min(d[0][(i - 1) % 2] + cost1[i], d[1][(i - 1) % 2] + cost1[i] + change21[i - 1]);
		d[1][i % 2] = min(d[1][(i - 1) % 2] + cost2[i], d[0][(i - 1) % 2] + cost2[i] + change12[i - 1]);
	}
}

int main()
{
	scanf("%d", &n);
	for(long long i = 1; i <= n; i++)
		scanf("%d", &cost1[i]);
	for(long long i = 1; i <= n; i++)
		scanf("%d", &cost2[i]);
	for(long long i = 1; i < n; i++)
		scanf("%d", &change12[i]);
	for(long long i = 1; i < n; i++)
		scanf("%d", &change21[i]);
	findcost();
	cout << min(d[0][n % 2], d[1][n % 2]) << endl;
}