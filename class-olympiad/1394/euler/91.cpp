#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>



using namespace std;

const int maxn = 50;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}


int main()
{
	int co = 0;
	for(int x = 1; x <= maxn; x++)
	{
		for(int y = 1; y <= maxn; y++)
		{
			int c = gcd(x, y);
			int p = x / c, q = y / c;
			int xp = x + q, yp = y - p;
			for(; xp <= maxn && yp >= 0 ; xp += q, yp -= p)
				co++;
			xp = x - q, yp = y + p;
			for(; xp >= 0 && yp <= maxn; xp -= q, yp += p)
				co++;
		}
	}
	cout << maxn * maxn * 3 + co  << endl;

}