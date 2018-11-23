#include <iostream>

using namespace std;

const int maxN = 1000 * 10 + 2;
int a[maxN];

int main()
{
	int n;
	cin >> n;
	for(int i = 1 ; i <= n; i++)
		a[i] = 1;
	if(n > 1)
		a[n] = 0;
	for(int i = 2; i <= n / 2; i++)
	{
		if(n % i == 0)
		{
			for(int j = 1; j * i <= n; j++)
				a[i * j] = 0;
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
		if(a[i])
			sum++;
	cout << sum << endl;

	
}