#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 1000 * 100;
int n;
int a[maxn + 100];
int p[maxn + 100];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &p[i]);
	int sum = p[0] * a[0], minim = p[0];
	for(int i = 1; i < n; i++)
	{
		if(p[i] < minim)
			minim = p[i];
		sum += minim * a[i];
	}
	cout << sum << endl;
}
