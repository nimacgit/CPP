/*
 * =====================================================================================
 *
 *       Filename:  459-C.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۱۸ ۱۳:۲۸:۳۴
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
int n, k, d;
const int maxn = 1000;
bool ispos[maxn + 100];


int main()
{
	cin >> n >> k >> d;
	int times = n / k;
	if(n % k != 0)
		times++;
	if((k == 1 && n > 1) || (d == 1 && n > k))
	{
		cout << -1 << endl;
		return 0;
	}
	int temp = n, tempd = d;
	bool flag = true;

	
	if(d == 1)
	{
		for(int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
		}
		cout << endl;
		return 0;
	}
while(flag)
	{
		if(temp % k != 0)
			temp = temp / k + 1;
		else
			temp = temp / k;
		tempd--;
		if(tempd == 1)
		{
			flag = false;
			if(temp > k)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	int co = n / k;
	if(n % k != 0)
		co++;
	int col = 0;
	int walk = 0;
	for(int i = 0; i < d; i++)
	{
		col = 0;
		for(int j = 0; j < n; j++)
		{
			if(ispos[j])
			{
				col = 0;
				walk = 0;
			}
			if(walk % co == 0)
			{
				ispos[j] = true;
				col++;
				walk = 0;
			}
			printf("%d ", col);
			walk++;
		}
		printf("\n");
		if(co % k != 0)
			co = co / k + 1;
		else
			co /= k;
	}
	return 0;
}

