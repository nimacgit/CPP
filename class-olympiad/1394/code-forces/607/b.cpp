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


const int maxn = 2 * 1000 * 100;
long long sum0 = 0, sum1 = 0, sum = 0;
string a,b;


int main()
{
	cin >> a >> b;
	int diff = b.length() - a.length();
	for(int i = 0; i <= diff; i++)
	{
		if(b[i] == '0')
			sum0++;
		else
			sum1++;
	}
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] == '0')
			sum += sum1;
		else
			sum += sum0;
		if(b[i] == '1')
			sum1--;
		else
			sum0--;
		if(b[diff + i + 1] == '1')
		{
			sum1++;
		}
		else
		{
			sum0++;
		}
	}
	cout << sum << endl;
	

}	
