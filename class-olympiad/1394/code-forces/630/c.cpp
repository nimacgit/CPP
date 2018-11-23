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
	long long ans = 2;
	for(int i = 0; i < n; i++)
		ans *= 2;
	ans-=2;
	cout << ans << endl;
}
