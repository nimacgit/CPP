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
long long sum = 0;
int minf = -1;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		sum+=(long long)temp;
		if(temp%2 == 1)
		{
			if(minf == -1)
				minf = temp;
			else
				minf = min(minf, temp);
		}
	}
	if(minf != -1 && sum % 2 == 1)
		sum -= minf;
	cout << sum << endl;


}
