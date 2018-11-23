#include <iostream>

using namespace std;

int main()
{
	int n, a = 1, b = 1, c,sum = 2;
	cin >> n;
	if(n == 0)
		sum = 0;
	if(n == 1 )
		sum = 1;
	if (n == 2)
		sum = 2;

	for(; n > 2; n--)
	{
		c = a + b;
		a = b;
		b = c;
		sum += c;
	}
	cout << sum << endl;
	
}