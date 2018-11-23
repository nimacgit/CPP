#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>


using namespace std;

const int maxn = 2000 * 1000 * 1000;
int x, y;
int i = 1;

int R()
{
	x++;
	int sum = 0;
	while(y != 0)
	{
		y--;
		if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
		x++;
		if(i + sum + 3 == maxn)
			cout << x << " " << y << endl;
		sum += 2;
	}
	return sum;
}
int D()
{
	y--;
	int sum = 0;
	while(x != 0)
	{
		y--;
		if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
		x--;
		if(i + sum + 3 == maxn)
			cout << x << " " << y << endl;
		sum+=2;
	}
	y++;
	return sum - 1;
}
int L()
{
	y++;
	int sum = 0;
	while(y != 0)
	{
		x--;
		if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
		y++;
		if(i + sum + 3 == maxn)
			cout << x << " " << y << endl;
		sum+=2;
	}
	x--;
	if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
	return sum + 1;
}
int U()
{
	y++;
	int sum = 0;
	while(x != 0)
	{
		x++;
		if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
		y++;
		if(i + sum + 3 == maxn)
			cout << x << " " << y << endl;
		sum+=2;
	}
	y++;
	if(i + sum + 2 == maxn)
			cout << x << " " << y << endl;
	return sum + 1;
}



int main()
{
	y = 1;
	x = 0;
	for(; i < maxn; i++)
	{
		i += R();
		i += D();
		i += L();
		i += U();
		//cout << i << "  " << x << "  " << y << endl;
	}
}