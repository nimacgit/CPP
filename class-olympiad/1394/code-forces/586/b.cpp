#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 50;
int a[maxn + 10][maxn + 10];
int b[maxn + 10];
int sum[maxn + 10];


typedef pair<int, int> pii;
#define mp make_pair 
int n;




int main()
{
	cin >> n;
	int s = 0;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			scanf("%d", &a[i][j]);
			if(i == 0)
				s += a[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	int w1 = s, w2 = 0;
	sum[0] = w1 + b[n - 1];
	for(int i = 1; i < n; i++)
	{
		w1 -= a[0][n - i - 1];
		w2 += a[1][n - i - 1];
		sum[i] = w1 + w2 + b[n - i - 1];
	}
	sort(sum, sum + n);
	cout << sum[0] + sum[1] << endl;

	
}