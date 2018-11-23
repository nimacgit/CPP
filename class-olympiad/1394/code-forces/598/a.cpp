#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 100;
long long n, t, sum, m, two;

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		two = 1;
		while(two <= n)
			two *= 2;
		sum = n * (n + 1) / 2 - 2 * (two - 1);
		cout << sum << endl;
	}
}
