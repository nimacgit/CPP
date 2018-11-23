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

int dig[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, m;


int f(int b)
{
	int sum = 0;
	while(b > 0)
	{
		sum += dig[b % 10];
		b /= 10;
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	long long sum = 0;
	while(n <= m)
	{
		sum += f(n);
		n++;
	}
	cout << sum << endl;

}	
