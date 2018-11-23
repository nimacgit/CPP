#include <iostream>

using namespace std;

const long long maxn = 400 + 3;
long long d[maxn][maxn];
long long a[maxn];
long long n;

void minpay()
{
	for(long long j = 1; j <= n; j++)
	{
		for(long long i = 1; j + i - 1 <= n; i++)
		{
			int minimum;
			if(j == 1)
			{
				minimum = 0;
			}
			else
				if(j == 2)
				{
					minimum = a[i] * a[i + 1] * a[i + 2];
				}
				else
				{
					for(int k = i; k < j + i - 1; k++)
					{
						if(k == i)
							minimum = d[k + 1][j + i - 1] + (a[i] * a[k + 1] * a[i + j]);
						else
							if(d[i][k] + d[k + 1][i + j - 1] + (a[i] * a[k + 1] * a[i + j]) < minimum)
								minimum = d[i][k] + d[k + 1][i + j - 1] + (a[i] * a[k + 1] * a[i + j]);
					}
				}
			d[i][j + i - 1] = minimum;
			//cout << minimum << " i = " << i << " j = " << j << endl;
		}
	}
}


int main()
{
	cin >> n;
	for(long long i = 1; i <= n + 1; i++)
		cin >> a[i];
	minpay();
	cout << d[1][n] << endl;
/*
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 1; j <= n; j++)
			cout << d[i][j] << " ";
		cout << endl;
	}
*/	

}