#include <iostream>

using namespace std;

int main()
{
	int n , m, sum = 0;
	cin >> n >> m;
	for(int i = 0, temp; i < m; i++)
	{
		cin >> temp;
		sum += temp;
	}
	cout << sum % n << endl;
}