#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 100;
char a[maxn + 10][maxn * maxn / 2 + 1000];
int chang;

char choos(int b)
{
	if(b == -1)
		return '\\';
	return '/';
}

int main()
{
	int n;
	cin >> n;
	int tempn = n;
	for(int j = 0; j < n; j++)
		for(int i = 0; i < n * (n + 1) / 2; i++)
			a[j][i] = ' ';
	if(n % 2 == 1)	
	{
		int x = n * (n + 1) / 2 - 1;
		int y = n - 1;
		chang = -1;
		while(tempn)
		{
			a[y][x] = choos(chang);
				x--;
			for(int i = tempn; i > 1; i--)
			{
				y += chang;
				a[y][x] = choos(chang);
				x--;
			}
			tempn--;
			chang *= -1;
		}
	}
	else
	{
		int x = n * (n + 1) / 2 - 1;
		int y = 0;
		chang = 1;
		while(tempn)
		{
			a[y][x] = choos(chang);
				x--;
			for(int i = tempn; i > 1; i--)
			{
				y += chang;
				a[y][x] = choos(chang);
				x--;
			}
			tempn--;
			chang *= -1;
		}
	}
	for(int j = 0; j < n; j++)
	{
		for(int i = 0; i < n * (n + 1) / 2; i++)
			cout << a[j][i];
		cout << endl;
	}
}