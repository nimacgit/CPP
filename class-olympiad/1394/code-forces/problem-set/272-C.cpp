/*
 * =====================================================================================
 *
 *       Filename:  272-C.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۵ ۱۷:۳۳:۰۶
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

const int maxn = 1000 * 100;
long long a[maxn + 100];
int n, m;


int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for(int i =0;i < m; i++)
	{
		long long w, h;
		cin >> w >> h;
		if(a[0] < a[w - 1])
			a[0] = a[w-1]+h;
		else
			a[0] += h;
		cout << a[0] - h << endl;
	}
	


}

