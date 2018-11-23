#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000, maxk = 100, mo = 1000 * 1000 * 1000 + 9;
int n, k;
long long d[maxn + 100][maxk + 100];
int a[maxn + 100];
long long sum[maxn + 100];


void dyn()
{
	d[0][0] = a[0];
	for(int i = 1; i < n; i++)
	{
		d[i][i] = (d[i - 1][i - 1] * a[i]) % mo;
		d[i][0] = sum[i];
	}
	for(int i = 2; i < n; i++)
	{
		for(int j = 1; j < k && j < i; j++)
		{
			d[i][j] = a[i] * d[i - 1][j - 1];
			int diff;
			for(int l = 1; l < j && l < i; l++)
			{	
				diff = sum[j] - sum[j - l];
				diff = diff * d[i - l][j - l];
				if(diff < d[i][j])
					d[i][j] = diff;
			}
		}
	}

}


int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i > 0)
			sum[i] = (sum[i - 1] + a[i]) % mo;
		else
			sum[0] = a[0];
	}
	dyn();
	cout << d[n - 1][k - 1] << endl;


}
