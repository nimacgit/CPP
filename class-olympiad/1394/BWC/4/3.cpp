/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۰/۳۰ ۲۱:۰۷:۴۴
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

const int maxn = 10000;
int delta = 648481;
unsigned long long factor[maxn + 100];

int main()
{
	factor[1] = 1;
	for(int i = 2; i < maxn; i++)
		factor[i] = factor[i - 1] * i;
	for(int i = 2; i * i < maxn; i++)
	{
		long long temp = factor[i * i];
		int k = i;
		while(k)
		{
			k--;
			temp /= factor[i];
		}
		if(temp >= delta)
		{cout << i << endl;
			cout << factor[i * i] << endl;
			int num = 1;
			for(int l = 1; l <= 1394; l++)
				num = (num * i) % delta;
			cout << num << endl;
			return 0;
		}
	}

}
