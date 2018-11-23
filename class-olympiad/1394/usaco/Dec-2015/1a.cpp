#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

int a, b, c, d;

int main()
{
	ifstream i;
	ofstream o;
	i.open("paint.in", ios::in);
	i >> a >> b;
	i >> c >> d;
	i.close();
	o.open("paint.out", ios::out);
	if(c >= a)
	{
		if(c <= b)
			o << max(b, d) - a << endl;
		else
		{
			o << b - a + d - c << endl;
		}
	}
	else
	{
		if(d >= a)
			o << max(d, b) - c << endl;
		else
			o << b - a + d - c << endl;
	}
	o.close();
	return 0;
}
