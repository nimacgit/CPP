#include <iostream>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 100 + 3;
long long h[maxn];
long long x[maxn];
int n;

int main()
{
	cin >> n;
	long long minnext;
	int cut = 0;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> h[i];
	minnext = x[0];
	cut++;
	for(int i = 1; i < n; i++)
	{
		if(x[i] - h[i] > minnext)
		{
			cut++;
			minnext = x[i];
		}
		else
		{
			if(i == n - 1 || x[i] + h[i] < x[i + 1])
			{
				cut++;
				minnext = x[i] + h[i];
			}
			else
			{
				minnext = x[i];
			}
		}
	}
	cout << cut << endl;

}