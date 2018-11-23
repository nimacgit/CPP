#include <iostream>

using namespace std;

const int maxn = 10000;
int d[2][maxn];

int main()
{
	int maxim = 0;
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> d[i % 2][j];
			if(i != 1)
			{
				d[i % 2][j] += max(d[(i - 1) % 2][j], d[(i - 1) % 2][j - 1]);
				if(d[i % 2][j] > maxim)
					maxim = d[i % 2][j];
			}

		}
	}
	cout << maxim << endl;
}