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

int main()
{
	cin >> n;
	cout << ((n%2) ? 1 : 2) << endl;
}