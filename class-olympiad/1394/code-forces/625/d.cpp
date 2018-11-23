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
const int maxn =  100 * 1000 + 100;
string s;

bool can(int k)
{
	bool flag = false;
	int *num = new int[s.length() + 10];
	int *num1 = new int[s.length() + 10];
	if(s.length() % 2 == 1)
	{
		if((s[s.length() / 2] - '0') % 2 == 1)
			flag = true;
		num[s.length() / 2] = s[s.length() / 2] - '0';
		num1[s.length() / 2] = num[s.length() / 2];
	}
	bool flag2 = true, flag1 = true;
	for(int i = s.length() / 2 - 1; i >= 0; i--)
	{

		num[s.length() - i - 1] = num[i] = 10 * (int)flag + s[i] - '0';
		num1[s.length() - i - 1] = num1[i] = num[i];
		flag = false;
		if(num[i] > 18)
		{
			if(num[i] == 19)
				flag = true;
			else
				return false;
		}	
	}
	if(s.length() % 2 == 1 && s[s.length() / 2] != '9')
		num1[s.length() / 2 + 1]++;

	if(flag)
		return false;
	for(int i = 0; i < s.length(); i++)
	{
		if(num[i] > 9)
		{
			num[i] -= 10;
			num[i + 1]++;
		}
		if(num1[i] > 9)
		{
			num1[i] -= 10;
			num1[i + 1]++;
		}
		if(s[i] - '0' != num[i])
			flag2 = false;
		if(s[i] - '0' != num1[i])
			flag1 = false;
		if(!flag1 && !flag2)
			return false;
	}
	return true;
}

void make(int a)
{
	int num[maxn];	
	bool flag = false;
	if(s.length() % 2 == 1)
	{
		if((s[s.length() / 2] - '0') % 2 == 1)
			flag = true;
		num[s.length() / 2] = (s[s.length() / 2] - '0') / 2;
	}
	for(int i = s.length() / 2 - 1; i >= 0; i--)
	{

		num[i] = (10 * (int)flag + s[i] - '0') / 2;
		num[s.length() - i - 1] = s[i] - '0' - num[i]; 
		flag = false;
		if(num[i] > 18)
			num[s.length() - i - 1]--;
	}
	int maxi = 0;
	for(int i = 0; i < s.length() + 3 ; i++)
	{
		if(num[i] > 9)
		{
			num[i] -= 10;
			num[i + 1]++;
		}
		if(num[i] != 0)
			maxi = i;
	}
	for(int i = maxi; i >= 0; i--)
		cout << num[i];
	cout << endl;
}


int main()
{
	cin >> s;
	int st = 0, e = s.length();
	while(st != e)
	{
		int mid = (st+e)/2;
		if(can(mid))
		{
			cerr << " true" << endl;
			e = mid;
		}
		else
			st = mid + 1;
	}

	if(st == s.length())
		cout << 0 << endl;
	else
		make(st);

}
