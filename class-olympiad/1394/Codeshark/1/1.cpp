#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int a, b;

int main()
{
	int k = 0;
	for(int i = 1; i <= a; i++)
	{
		if(i % a == 0 && i % b != 0)
			k++;
	}
	cout << k << endl;

}
