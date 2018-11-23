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
int a[2000];

int main()
{
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i < 1374; i++)
	{
		bool f = true;
		a[i] = a[i - 1];
		while(f)
		{
			a[i]++;
			f = false;
			for(int j = 1; j < i; j++)
			{
				for(int k = 0; k < j; k++)
					if(a[i] - a[j] == a[j] - a[k])
						f = true;
			}
		}
	}
	for(int i = 0; i < 1374; i++)
		cout << i << "  " << a[i] << endl;
}
