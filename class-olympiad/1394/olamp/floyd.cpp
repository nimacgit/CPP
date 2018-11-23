/*
 * =====================================================================================
 *
 *       Filename:  floyd.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۱/۱۳ ۱۷:۴۲:۳۰
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

const int maxn =  500;
const int inf = 1000 * 1000 * 1000;
int mat[maxn][maxn];

void smn(int & a, const int & b){ if(a>b) a=b; }


void pre()
{
	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j < maxn; j++)
			mat[i][j] = inf;
		mat[i][i] = 0;
	}
}

void floyd()
{
	for(int s = 0; s < n; s++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				smn(mat[i][j], mat[i][s] + mat[s][j]);
				smn(mat[j][i], mat[i][s] + mat[s][j]);
			}
}





int main()
{

}

