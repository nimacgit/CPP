/*
 * =====================================================================================
 *
 *       Filename:  dsu.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  ۱۵/۱۲/۲۲ ۱۷:۰۷:۲۰
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
int par[maxn + 1000];
int nsize[maxn + 1000];
int n;

void pre()
{
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
		nsize[i] = 1;
	}
}

int fpar(int p)
{
	if(par[par[p]] == par[p])
		return p;
	return par[p] = fpar(par[p]);
}

void merge(int p1, int p2)
{
	int p3 = fpar(p1), p4 = fpar(p2);
	if(p3 == p4)
		return;
	if(nsize[p3] > nsize[p4])
		swap(p3, p4);
	par[p3] = p4;
	nsize[p4] += nsize[p3];		
}




int main()
{

}
