#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int delta = 12569;
const int maxn = 1200;
int d[maxn];


void dyn()
{
	d[0] = 1;
	for(int i = 0; i < maxn; i++)
		for(int j = 2; (i + 1) * j - 1 < maxn; j++)
			d[(i + 1) * j - 1] += d[i];
}

int main()
{
	dyn();
	for(int i = 0; i < maxn; i++)
		cout << i + 1 << "  " << d[i] << endl;
	cout << (d[maxn - 1] % delta) * (d[maxn - 1] % delta) * (d[maxn - 1] % delta) % delta << endl;
}