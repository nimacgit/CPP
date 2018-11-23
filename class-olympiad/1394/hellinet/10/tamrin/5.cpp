#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 3 * 1000 * 100;
long long d[maxn + 100];
int p[maxn + 100];
int x[maxn + 100];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	long long maxlit = p[0];
	d[0] = 0;
	for(int i = 1; i < n; i++)
	{
		int dis = x[i] - x[i - 1];
		if(p[i - 1] < maxlit)
			maxlit = p[i - 1];
		d[i] = d[i - 1] + maxlit * dis;
	}
	cout << d[n - 1] << endl;
}