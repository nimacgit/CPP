#include <iostream>

using namespace std;

const int maxn = 1000;
long long C[maxn][maxn];

long long cn(int n, int i)
{
	if(i > n)
		return C[n][i] = 0;
	if(n == i)
		return C[n][i] = 1;
	if(i == 0)
		return C[n][i] = 1;
	if(n == 0)
		return C[n][i] = 0;
	if(C[n - 1][i] == -1)
		cn(n - 1, i);
	if(C[n - 1][i - 1] == -1)
		cn(n - 1, i - 1);
	return C[n][i] = C[n - 1][i] + C[n - 1][i - 1];
}

int main()
{
	int n, i;
	cin >> n >> i;
	for (int k = 0; k <= n; k++)
		for(int j = 0; j <= n; j++)
			C[j][k] = -1;
	cout << cn(n, i) << endl;
/*	for (int k = 0; k <= n; k++)
		for(int j = 0; j <= n; j++)
			cerr << "c[" << j << "][" << k << "] = " << C[j][k] << endl;
*/
}