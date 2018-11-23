/*
 * =====================================================================================
 *
 *       Filename:  272-B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۵ ۱۷:۱۴:۱۱
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int ones[maxn + 10];
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp, co = 0;
		scanf("%d", &temp);
		while(temp > 0)
		{
			if(temp % 2 == 1)
				co++;
			temp /= 2;
		}
		ones[co]++;
	}
	long long sum = 0;
	for(int i = 0; i < maxn + 5; i++)
		sum += (long long)ones[i] * (long long)(ones[i] - 1) / 2;
	cout << sum << endl;

}

