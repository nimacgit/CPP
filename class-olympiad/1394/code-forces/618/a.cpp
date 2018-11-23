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
vector<int> num;

int main()
{
	cin >> n;
	int co = 1; 
	while(n > 0)
	{
		if(n % 2 != 0)
			num.push_back(co);
		co++;
		n /= 2;
	}
	for(int i = num.size() - 1; i >= 0; i--)
		cout << num[i] << " ";
	cout << endl;


}
