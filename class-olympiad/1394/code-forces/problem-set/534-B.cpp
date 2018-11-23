#include <iostream>

using namespace std;

const int maxv = 1100 + 100, maxt = 100 + 10;
int d, t, v1, v2;
int dyn[maxt][maxv];
bool isuse[maxt][maxv];

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

void dynamic()
{
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= v1 + t * d; j++)
		{
			dyn[i][j] = 0;
			isuse[i][j] = false;
		}
	}
	for(int i = 1; i <= v1 + t * d; i++)
	{
		if(abs(v1 - i) <= d)
		{
			dyn[1][i] = v1;
			isuse[1][i] = true;
		}
		else
			dyn[1][i] = 0;
	}
	for(int i = 2; i < t; i++)
	{
		for(int j = 1; j <= v1 + t * d; j++)
		{
			dyn[i][j] = -1;
			for(int k = max(j - d, 1); k <= v1 + t * d && k <= j + d; k++)
			{
				if(isuse[i - 1][k])
					dyn[i][j] = max(dyn[i][j], dyn[i - 1][k] + k);
			}
			if(dyn[i][j] != -1)
				isuse[i][j] = true;
		}
	}

}

int main()
{
	cin >> v1 >> v2 >> t >> d;
	dynamic();

	cout << dyn[t - 1][v2] + v2 << endl;
}
