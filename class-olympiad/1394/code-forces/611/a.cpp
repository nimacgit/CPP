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

long long n;
string s1;

int main()
{
	cin >> n;
	cin >> s1 >> s1;
	if(s1[0] == 'm')
	{
		if(n <= 29)
			cout << 12 << endl;
		else if(n == 30)
			cout << 11 << endl;
		else
			cout << 7 << endl;
	}
	else
	{
		if(n < 5)
			cout << 52 << endl;
		else if(n == 7)
			cout << 52 << endl;
		else
			cout << 53 << endl;
	}
	
}
