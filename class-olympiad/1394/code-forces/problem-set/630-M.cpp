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
int d[4];
int mini = 0;

int dis(int k)
{
	k = abs(k);
	return min(k, 360 - k);
}

int main()
{
	cin >> n;
	n *= (long long)-1;
	n = n % 360;
	if(n < 0)
		n += 360;
	d[0] = dis(n);
	for(int i = 1; i < 4; i++)
	{
		n = (n + 90) % 360;
		d[i] = dis(n);
		if(d[i] < d[mini])
			mini = i;
	}
	cout << mini << endl;
}
