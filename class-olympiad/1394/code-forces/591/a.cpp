#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 1000 * 10;
long long p,q, l;

int main()
{
	cin >> l >> p >> q;
	p *= maxn;
	q *= maxn;
	l *= maxn;
	cout << (double)(double(((p * l) / (p + q))) / maxn) << endl;
}
