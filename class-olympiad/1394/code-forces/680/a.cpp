#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int num[5];
int t[5];
int n = 1;

int main()
{
	cin >> num[0];
	t[0] = 1;
	int sum = num[0];
	for(int i = 1; i < 5; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		bool flag = false;
		for(int j = 0; j < n && !flag; j++)
		{
			if(temp == num[j])	
			{
				flag = true;
				t[j]++;
			}
		}
		if(!flag)
		{
			num[n] = temp;
			t[n] = 1;
			n++;
		}
	}
	int maxi = 0;
	for(int i = 0; i < n; i++)
	{
		if(t[i] > 1)
		maxi = max(maxi, min(3, t[i])*num[i]);
	}
	cout << sum - maxi << endl;
}
