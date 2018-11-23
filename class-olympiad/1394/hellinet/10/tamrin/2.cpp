#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	long long n , k;
	cin >> n >> k;
	long long baghi = n / 2;
	if(n % 2 == 1)
		baghi++;
	if(k > baghi)
		cout << (k - baghi) * 2 << endl;
	else
		cout << 2 * k - 1 << endl;
}