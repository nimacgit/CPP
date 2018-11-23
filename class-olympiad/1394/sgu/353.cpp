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


int n, p1, p2, p3, k1, k2, times = 0;

int main()
{

	cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
	if(p1 > n)
	{
		cout << 0 << endl;
		return 0;
	}
	n -= p1;
	times += k1;
	times += (n / p2) * (k2);
	n %= p2;
	times += n / p3;
	cout << times << endl;
	return 0;
}