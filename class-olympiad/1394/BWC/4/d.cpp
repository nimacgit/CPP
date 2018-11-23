/*
 * =====================================================================================
 *
 *       Filename:  d.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۰/۳۰ ۲۰:۱۷:۴۱
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


const int maxn = 1000;
int d[maxn + 100][maxn + 100];

int main()
{
	d[0][0] = 0;
	for(int i = 1; i <= maxn; i++)
	{
		d[0][i] =  d[i][0] = 0;
		for(int k = 1; k <= i; k *= 2)
		{
			if(d[0][i - k] == 0)
				d[0][i] = 1;
			if(d[i - k][0] == 0)
				d[i][0] = 1;
		}
	}
	for(int i = 1; i <= maxn; i++)
	{
		for(int j = 1; j<= maxn; j++)
		{
			d[i][j] = 0;
			for(int k = 1; k <= i; k*= 2)
			{
				if(d[i - k][j] == 0)
					d[i][j] = 1;
			}

			for(int k = 1; k <= j; k*= 2)
			{
				if(d[i][j - k] == 0)
					d[i][j] = 1;
			}
		}
	}
	long long co = 0;
	int delta = 648481;
	for(int i = 0; i <= maxn; i++)
	{
		for(int j = 0; j <= maxn; j++)
			if(d[i][j] == 1)
				co++;
	}
	cout << co <<  endl;
	cout << (((co * co)%delta) * co) % delta << endl;
}
