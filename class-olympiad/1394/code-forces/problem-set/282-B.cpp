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
bool choo[maxn + 100];
int n;
long long dif = 0;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		if(dif + temp1 <= 500)
		{
			choo[i] = true;
			dif += temp1;
		}
		else
		{
			choo[i] = false;
			dif -= temp2;
		}
	}
		for(int i = 0; i < n; i++)
		{
			if(choo[i])
				cout << "A";
			else
				cout << "G";
		}
		cout << endl;
}
