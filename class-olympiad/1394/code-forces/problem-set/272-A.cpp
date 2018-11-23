/*
 * =====================================================================================
 *
 *       Filename:  272-A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۵ ۱۶:۵۶:۳۸
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
int sum = 0, n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum+=temp;
	}
	n++;
	int co = 0;
	for(int i = 0; i < 5; i++)
		if((sum + i + 1)  % n != 1)
			co++;
	cout << co << endl;

}
