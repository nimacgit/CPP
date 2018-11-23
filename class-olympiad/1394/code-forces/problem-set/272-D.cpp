/*
 * =====================================================================================
 *
 *       Filename:  272-D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۵ ۲۲:۰۹:۰۵
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int,int> pie;

const int maxn = 1000 * 100;
int n, m;
int a[maxn + 100], b[maxn + 100];
int co = 0;
long long mult = 1;
vector<int>myv;
vector<int> nums;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		myv.push_back(a[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		if(a[i] == b[i])
			co++;
		myv.push_back(b[i]);
	}
	sort(myv.begin(), myv.end());
	cin >> m;
	int l = 1;
	for(int i = 1; i < myv.size(); i++)
	{
		if(myv[i] == myv[i - 1])
			l++;
		else
		{
			nums.push_back(l);
			l = 1;
		}
	}
	nums.push_back(l);
	for(int i = 0; i < nums.size(); i++)
	{
		int con = nums[i];
		while(con > 1)
		{
			int sum = con;
			while(co > 0 && sum % 2 ==0)
			{
				co--;
				sum/=2;
			}
			mult = (mult * sum) % m;
			con--;
		}
	}
	cout << mult << endl;



}

