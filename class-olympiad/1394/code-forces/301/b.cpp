#include <iostream>
#include <algorithm>

using namespace std;

int n, k, p, x, y;
int a[1000];

int main()
{
	cin >> n >> k >> p >> x >> y;
	int sum = 0, mid;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n + 1);
	mid = a[(n + 1) / 2];
	cout << mid << endl;



}