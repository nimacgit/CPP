#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000 * 10;
const int delta = 12841;
int v[maxn * maxn + 2][2];
int k = 0;

int bmm(int a, int b)
{
	int w, z;
	if(a < b)
		swap(a , b);
	//cout << a << " " << b << " ";
	for(int c = a % b; c > 0;)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int abs(int a)
{
	if(a < 0)
		return -1 * a;
	return a;
}

int dis(int i)
{
	int suma = 0;
	for(int j = i - 1; j > 0; j--)
		suma = (suma + abs(v[i][1] - v[j][1]) + abs(v[i][2] - v[j][2])) % delta;
	return suma;
}

int main()
{
	int sum = 0;
	for(int i = 0; i < maxn; i++)
	{
		for(int j = i; j < maxn; j++)
			if(bmm(i + 1, j + 1) == 1)
			{
				v[k][1] = i + 1;
				v[k][2] = j + 1;
				sum = (sum + dis(k)) % delta;
				k++;
				v[k][1] = j + 1;
				v[k][2] = i + 1;
				sum = (sum + dis(k)) % delta;
				k++;
			}
	}
	cout << sum << endl;
	
}