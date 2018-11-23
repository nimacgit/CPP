#include <iostream>

using namespace std;

int main()
{
	long long n, m , a, n1, m1;
	cin >> n >> m >> a;
	n1 = n / a;
	if(n % a != 0)
		n1++;
	m1 = m / a;
	if(m % a != 0)
		m1++;
	cout << n1 * m1 << endl;
}