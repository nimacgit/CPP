/*
 * =====================================================================================
 *
 *       Filename:  459-B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۱۸ ۱۳:۱۸:۵۶
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

const int maxn  = 2 * 100 * 1000;
int n;
int a[maxn + 100];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	cout << a[n - 1] - a[0] << " ";
	if(a[n-1]==a[0])
		cout << (long long)n*(n-1)/2 << endl;
	else
	{
		long long co = 1, so = 1;
		for(int i = 0; i < n && a[i] == a[i + 1]; i++)
			co++;
		for(int i = n - 1; i > 0 && a[i] == a[i - 1]; i--)
			so++;
		cout << (long long)so * co << endl;
	}
}

