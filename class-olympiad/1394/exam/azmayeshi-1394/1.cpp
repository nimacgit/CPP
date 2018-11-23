#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int maxn = 1000;
//int d[maxn + 2][maxn + 2];

int bmm(int a, int b)
{
	int w, z;
	w = a;
	z = b;
	if(a < b)
		swap(a , b);
	//cout << a << " " << b << " ";
	for(int c = a % b; c > 0;)
	{
		a = b;
		b = c;
		c = a % b;
	}
//	d[w][z] = b;
	//cout << b << endl;
	return b;
}


int main()
{
	long long sum = 0;
	for(int a = 1; a <= maxn; a++)
	{
		for(int b = a + 2; b <= maxn; b += 2)
		{
			if(bmm(a, b) == bmm((a + b) / 2, (b - a) / 2))
			{
				cout << a << "  " << b << "  " << (a + b) / 2 << "  " << (b - a) / 2 << endl; 
				sum++;
			}
		}
	}
	cout << sum % 12841 << endl;
}

