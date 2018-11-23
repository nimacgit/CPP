#include <iostream>

using namespace std;

const int maxn = 1000;
unsigned long long C[maxn][maxn];

unsigned long long cn(int n, int i)
{
	C[0][0] = 1;
	for(int j = 1; j <= n; j++)
	{
		C[0][j] = 1; 
		for(int k = 1; k <= j; k++)
		{
			C[k][j] = C[k - 1][j - 1] + C[k][j - 1];
		}
	}
	return C[i][n];
}

int main()
{
	unsigned long long sum = cn(110, 10) + cn(109, 9) - 2 - 1000;
	cout << sum << endl;
}