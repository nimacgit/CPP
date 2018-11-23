#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 10000;
const int delta = 229939;
const int k = 4;
bool check[maxn * maxn];
bool check2[maxn * maxn];


int main()
{
	int a[8] = {972 , -1, 273, -1, 932, 911, -1, 233};
	int b[8] = {-1, 942, 135, -1, 371, -1, 311, -1};
	int sum = 0;
	for(int x1 = maxn / 10; x1 < maxn; x1++)	
	{
		for(int x = 0; x < 311; x++)
			if(((233 * x + 8) % x1 ) == 777)
				check[x] = true;
	}
	for(int x1 = maxn / 10; x1 < maxn; x1++)	
	{
		for(int x = 0; x < 10000; x++)
			if(check[((x1 * x + 7) % 311)])
			{
				check2[x] = true;
				sum++;
			}
	}
		for(int x1 = maxn / 10; x1 < maxn; x1++)	
	{
		for(int x = maxn / 10; x < maxn; x++)
			if(check2[(((((4 % x1 ) * 932 + 5)% 371) * 911) + 6) % x1])
				sum++;
	}
	cout << sum << endl;
}