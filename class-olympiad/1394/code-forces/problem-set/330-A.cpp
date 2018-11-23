/*
 * =====================================================================================
 *
 *       Filename:  330-A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۳ ۱۰:۵۱:۴۴
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
const int maxn = 10;
int r, c;
bool ev[maxn + 10][maxn + 10];
bool eat[maxn + 10][maxn + 10];
bool row[maxn + 10], col[maxn + 10];
int sum = 0;
string s;

int main()
{
	cin >> c >> r;
	for(int i = 0; i < c; i++)
	{
		cin >> s;
		for(int j = 0; j < r; j++)
			if(s[j] == 'S')
			{
				col[j]=true;
				row[i] = true;
				ev[i][j] = true;
			}
	}
	for(int i = 0; i < c; i++)
	{
		if(!row[i])
			for(int j = 0; j < r; j++)
			{
				if(!eat[i][j])
				{
					eat[i][j] = true;
					sum++;
				}
			}
	}
	for(int i = 0; i < r; i++)
	{
		if(!col[i])
			for(int j = 0; j < c; j++)
			{
				if(!eat[j][i])
				{
					eat[j][i]  =true;
					sum++;
				}
			}
	}
	cout << sum << endl;
}

