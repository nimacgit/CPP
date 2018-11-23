#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

const int maxn = 1000 * 100;
int n, minim = maxn * 20000;
int bids[maxn + 100];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> bids[i];
		if(minim > bids[i])
			minim = bids[i];
	}
	for(int i = 0; i < n; i++)
	{
		int temp = gcd(minim, bids[i]);
		int bcd = minim / temp;
		while(bcd % 2 == 0)
			bcd /= 2;
		while(bcd % 3 == 0)
			bcd /= 3;
		if(bcd != 1)
		{
			cout << "NO" << endl;
			return 0;
		}
		bcd = bids[i] / temp;
		while(bcd % 2 == 0)
			bcd /= 2;
		while(bcd % 3 == 0)
			bcd /= 3;
		if(bcd != 1)
		{
			cout << "NO" << endl;
			return 0;
		}

	}
	cout << "YES" << endl;
}