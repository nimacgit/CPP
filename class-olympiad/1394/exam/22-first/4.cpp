#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	int s[10][10];
	int d[33];
	for(int i = 0; i < 33; i++)
		d[i] = 0;
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cin >> s[i][j];
			d[s[i][j]]++;
		}
	}
	int maxim = 9, minim = 21;
	for(int i = 1; i < 33; i++)
	{
		if(d[maxim] == d[i])
		{
			cout << " maxim " << i << endl;
			maxim = i;
		}
		if(d[minim] == d[i])
		{
			minim = i;
			cout << " min " << i << endl;
		}
	}
	cout << maxim << "  " << minim << "  " << d[maxim] << " " << d[minim] << endl;

	//maxim = خ , minim = ع
}