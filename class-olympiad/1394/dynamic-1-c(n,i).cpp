#include <iostream>

using namespace std;

const int maxn = 1000;
int C[maxn][maxn];

long long cn(int n, int i)
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
	int n, i;
	cin >> n >> i;
	cout << cn(n, i) << endl;
}