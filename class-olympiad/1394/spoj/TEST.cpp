/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۶/۰۲/۰۱ ۱۸:۵۴:۴۵
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include<bits/stdc++.h>

using namespace std;

int t, n, w;

int main()
{
	n = 1000 * 100;
	cout << n << endl;
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		long long num = rand() % 1000000000;
		cout << num * (long long)1000 << " "; 
	}
	cout << endl;
	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << 0 << " "  <<  1 << " " << n << endl;
	cout << -1 << endl;
}
