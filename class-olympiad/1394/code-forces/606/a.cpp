#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

const int maxn = 5;
int a, b, c, x, y, z;
int main()
{
	int unuse = 0;
	cin >> a >> b >> c >> x >> y >> z;
	unuse += max(0, (a - x)/2);
	unuse += max(0, (b - y)/2);
	unuse += max(0, (c - z)/2);
	if(a < x)
		unuse -= x - a;
	if(b < y)
		unuse -= y - b;
	if(c < z)
		unuse -= z - c;
	if(unuse < 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

}
