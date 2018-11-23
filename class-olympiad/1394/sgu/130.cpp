#include <iostream>

using namespace std;

const unsigned long long  maxn = 60 + 5;
unsigned long long  ak[maxn];

void ways(unsigned long long  k)
{
	ak[k] = 0;
	for(unsigned long long  i = 2; i <= k; i += 2)
	{
		if(ak[k - i] == -1)
			ways(k - i);
		if(ak[i - 2] == -1)
			ways(i - 2);
		ak[k] += ak[k - i] * ak[i - 2];
	}
}

int main()
{
	unsigned long long  n;
	cin >> n;
	for(unsigned long long  i = 0; i <= 2 * n; i++)
		ak[i] = -1;
	ak[0] = 1;
	ways(2 * n);
	cout << ak[2 * n] << " ";
	cout << n + 1 << endl;
	
}