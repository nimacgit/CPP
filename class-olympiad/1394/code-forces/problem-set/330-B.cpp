/*
 * =====================================================================================
 *
 *       Filename:  330-B.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۳ ۱۱:۰۲:۴۶
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
int n, m;
bool cant[maxn + 100];



int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int temp[2];
		scanf("%d %d", &temp[0], &temp[1]);
		temp[0]--;
		temp[1]--;
		cant[temp[0]] = cant[temp[1]] = true;
	}
	for(int i = 0; i < n; i++)
	{
		if(!cant[i])
		{
			cout << n - 1 << endl;
			for(int j = 0; j < n; j++)
				if(j != i)
					cout << i + 1 << " " << j + 1 << endl;
			return 0;
		}
	}
}

