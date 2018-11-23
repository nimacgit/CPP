#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

long long m, h1, a1, x1, y1, h2, a2, x2, y2, max1 = -1, max2 = -1;

long long gc(long long a, long long b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int main()
{
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	for(int i = 0; i <= m; i++)
	{
		//cerr << h1 << "  " << h2 << endl;
		h1 = (x1 * h1 + y1) % m;
		if(h1 == a1)
		{
			max1 = i + 1;
			i = m + 10;
		}
	}
	for(int i = 0; i <= m; i++)
	{
		h2 = (x2 * h2 + y2) % m;
		if(h2 == a2)
		{
			max2 = i + 1;
			i = m +‌ 10;
		}
	}
	if(max2 == -1 || max1 == -1)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << max2 * max1 / gc(max1, max2) << endl;
}