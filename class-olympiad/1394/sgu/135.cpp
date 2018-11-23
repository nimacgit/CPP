#include <iostream>

using namespace std;

int main()
{
	long long n;
	long long sum;
	cin >> n;
	sum = n + 1 + ((n * (n-1)) / 2);
	cout << sum << endl;
	
}