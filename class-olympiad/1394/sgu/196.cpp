#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;


const int maxn = 1000 * 10;
int degree[maxn + 100];
int n, m;
long long sum = 0;
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		temp1--;
		temp2--;
		degree[temp1]++;
		degree[temp2]++;
	}
	for(int i = 0; i < n; i++)
		sum += degree[i] * degree[i];
	cout << sum << endl;
	
}