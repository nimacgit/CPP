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
long double a, b, c;

int main()
{
	cout.precision(20);
	cout << fixed;
	cin >> a >> b >> c;
	if(a >= 0)
	{
		cout << (-b + sqrt(b*b - (long double)4*a*c)) / ((long double)2 * a) << endl;
		cout << (-b - sqrt(b*b - (long double)4*a*c)) / ((long double)2 * a) << endl;
	}
	else
	{
		cout << (-b - sqrt(b*b - (long double)4*a*c)) / ((long double)2 * a) << endl;
		cout << (-b + sqrt(b*b - (long double)4*a*c)) / ((long double)2 * a) << endl;
	}
}
