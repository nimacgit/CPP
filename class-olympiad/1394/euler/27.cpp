#include <iostream>

using namespace std;

const int maxn = 1001;

int main()
{
	long long sum = 1;
	for(int i = 1, k = 2; i <= (maxn - 1)/2; i++, k += 2)
	{
		sum += (k - 1) * k + k * k + (k + 1) * k + (k + 2) * k + 4;
	}
	cout << sum << endl;
}