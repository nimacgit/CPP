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

long double sin72 = 0.951056516, sin54 = 0.809016994, l1, l2, l3, s1, s2, s3, a3, h3, sq3 = sqrt(3), sq2 = sqrt(2);
long double ans;


int main()
{
	cin >> l1 >> l2 >> l3;
	cout.precision(20);
	cout << fixed;
	s1 = (l1 * l1 * l1) / (6*sq2);
	s2 = (l2 * l2 * l2) / (sq2 * 3);
	a3 = (sin54 * l3) / sin72;
	h3 = sqrt(l3 * l3 - a3 * a3);
	s3 = a3 * a3 * sin72 / 2;
	ans = s1 + s2 + s3 * h3 / 3;
	cout << ans << endl;

	
}
