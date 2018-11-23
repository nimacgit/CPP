#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 100;
int l[maxn + 100];
int d[210];
int n;
int work[2][maxn + 100];


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> work[0][i] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> l[i];
		work[0][l[i]]++;
	}
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < n; i++)
		work[1][i] = wo
}