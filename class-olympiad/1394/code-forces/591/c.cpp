#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

const int maxn = 500 * 1000;
int n, maxim = 0;
int num[maxn + 100];


int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);	
	int das = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == n - 1 || num[i] == num[i + 1])
		{
			int first = i;
			while(i < n - 1 && num[i] == num[i + 1] )
				i++;
			int co = 0;
			for(int j = das + 1; j <= (first + das) / 2; j++)
			{
				co++;
				num[j] = num[das];
			}
			for(int j = (first + das) / 2 + 1; j < first; j++)
				num[j] = num[first];
			maxim = max(maxim, co);
			das = i;
		}
	}
	cout << maxim << endl;
	for(int i = 0; i < n; i++)
		printf("%d ", num[i]);
	cout << endl;
	 	
	
}
