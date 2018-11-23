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

const int maxn = 1000 * 1000;
int n;

int main()
{
	cin >> n;
	if(n % 5 == 0)
		cout << n / 5 << endl;
	else
		cout << n / 5 + 1 << endl;


}
