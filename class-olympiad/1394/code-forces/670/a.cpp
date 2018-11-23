#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int n;

int main()
{
	cin >> n;
	if(n % 7 == 1)
		cout << (n / 7) * 2 << " " << ((n + 6) / 7 ) * 2 - 1 << endl;
	else if(n % 7 == 6)
		cout << (n / 7) * 2 + 1 << " " << ((n + 6) / 7) * 2 << endl;
	else
		cout << (n / 7) * 2 << " " << ((n + 6) / 7) * 2 << endl;
}
