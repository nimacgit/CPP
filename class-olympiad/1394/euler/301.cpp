#include <iostream>

using namespace std;

const int maxn = 1073741824;

int main()
{
	int n = 1, sum = 0;
	while(n <= maxn)
	{
		if((n ^ (2 * n) ^ (3 * n)) == 0)
			sum++;
		n++;
	}
	cout << sum << endl;
}