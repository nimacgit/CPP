/*
 * =====================================================================================
 *
 *       Filename:  T-acidpash.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۱/۰۴ ۱۸:۱۰:۵۵
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


const int maxn = 1000 * 1000;
int arr[maxn + 100];
int dyn[maxn + 100];
bool seens[maxn + 100][4];
int n, m;


int a(int i, int j)
{
	return arr[i * m + j];
}
int d(int i, int j,int k)
{
	return dyn[i * m + j][k];
}
int seen(int i, int j,int k)
{
	return seens[i * m + j][k];
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &arr[i * m + j]);
	for(int i = 0  





}
