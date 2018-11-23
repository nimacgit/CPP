#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>



using namespace std;

int main()
{
	int t = 0, x1, y1, y2, x2;
	cin >> t;
	long long sum = 0;
	for(int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		sum += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	cout << sum << endl;

}