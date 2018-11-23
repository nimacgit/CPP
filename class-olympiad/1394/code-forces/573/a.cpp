#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <deque>


using namespace std;

const int maxn = 100;
const int maxim = 1000;
int n, nima;
set <int> myset;
int a[maxim + 100];

int main()
{
	cin >> n;
	cin >> nima;
	for(int i = 0; i < maxim; i++)
		a[maxim] = 0;
	for(int i = 1; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[temp]++;
		temp *= -1;
		if(a[temp * -1] == 1)
			myset.insert(temp);
	}
	int co = 0;
	while(-1 * (*myset.begin()) >= nima)
	{
		co++;
		int temp = *myset.begin();
		myset.erase(myset.begin());
		a[temp * -1]--;
		nima++;
		temp++;
		if(a[((temp - 1) * -1)] > 0)
			myset.insert(temp - 1);
		a[-1 * temp]++;
		myset.insert(temp);
	}
	cout << co << endl;
}