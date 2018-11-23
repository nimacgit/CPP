#include <iostream>

using namespace std;

int f(int n, int i)
{
	int roof;
	if(n == 1)
		return 1;
	if(n % 2 == 0)
		roof = 0;
	else
		roof = 1;
	if(i > n /2)
	{
		return f((n/2) + roof, (n - i + 1));
	}
	else
		return n/2 + roof + f(n/2, n / 2 + 1  - i);

}

int main()
{
	int n, i;
	cin >> n >> i;
	cout << f(n, i) << endl;
	
}