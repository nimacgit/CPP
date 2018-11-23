#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 100;
int n;
int a[maxn + 100];
int co;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int i = 0;
	for(; i < n && a[i] != 1; i++)
	{

	};
	for(;i < n; i++)
	{
		if(i < n - 1 && a[i] == 0 && a[i + 1]== 0)
		{
			for(; i < n && a[i] == 0; i++)
			{

			};
			i--;
		}
		else if(!(i == n - 1 && a[i] == 0))
			co++;
	}
	cout << co << endl;
}
