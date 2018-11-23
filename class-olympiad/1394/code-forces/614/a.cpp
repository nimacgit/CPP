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
long long l, r, k;

int main()
{
	cin >> l >> r >> k;
	bool flag = false;
	long long sum = (long long)(1);
	while(sum < l && sum > 0 && LLONG_MAX / k >= sum)
		sum *= k;
	while(sum >= l && sum <= r && sum > 0)
	{
		flag = true;
		cout << sum << " ";
		if(LLONG_MAX / k < sum)
		{
			sum = 0;
		}
		else
			sum *= k;
	}
	if(!flag)
		cout << -1;
	cout << endl;


}
