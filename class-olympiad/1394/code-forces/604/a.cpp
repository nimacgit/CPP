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

const int maxn = 5;
int m[maxn], w[maxn];
int s, u;
long long sum = 0;
long long score = 500;

int main()
{
	for(int i = 0; i < maxn; i++)
		cin >> m[i];
	for(int i = 0; i < maxn; i++)
		cin >> w[i];
	cin >> s >> u;
	for(int i = 0; i < maxn; i++)
	{
		if(25 * 3 * score*(i + 1) >= (250 - m[i]) * score * (i+1) - 250 * 50 * w[i])
			sum += 3 * score * (i + 1) * 25;
		else
		{
			sum += (250 - m[i]) * score * (i+1) - 250 * 50 * w[i];
		}
	}
	sum /= 250;
	sum += s * 100;
	sum -= u * 50;
	cout << sum << endl;

}
