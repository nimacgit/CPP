#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 1000 * 1000;
int n;
int w[maxn + 1000];
int powers[maxn + 1000];
int maxgo = 0;
int co = 0;

int main()
{
	fill(powers, powers + maxn, 0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		powers[w[i]]++;
		if(w[i] > maxgo)
			maxgo = w[i];
		int j = w[i];
		while(powers[j] > 1)
		{
			powers[j] -= 2;
			powers[j + 1]++;
			j++;
			if(j > maxgo)
				maxgo = j;
		}
	}
	bool flag = false;
	for(int i = 0; i <= maxgo; i++)
	{
		if(powers[i] == 2)
		{
			flag = true;
			co++;
		}
		else if(powers[i] == 1)
		{
			if(!flag)
				co++;
		}
		else
			flag = false;

	}
	cout << co << endl;
	
}