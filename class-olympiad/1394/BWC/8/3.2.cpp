#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long f1 = 1, f2 = 2, f3 = 4, sum = 7, n = 10000000000000000;
int mo = 648481;
vector<long long> mv;

int main()
{
	mv.push_back(1);
	mv.push_back(2);
	mv.push_back(4);
	while(sum <= n)
	{
		f1 = (f2 + f1 + f3);
		swap(f3, f1);
		swap(f2, f1);
		sum += f3;
		mv.push_back(f3);
	}
	for(int i = 0; i < mv.size(); i++)
		cout << mv[i] << endl;
}
