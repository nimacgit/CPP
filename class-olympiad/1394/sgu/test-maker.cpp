#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

using namespace std;




int main()
{
	srand (time(NULL));
	string a;
	for(int i = 0; i < 5000; i++)
		if(rand() % 2 == 0)
			a += '-';
		else
			a += '+';
	cout << a << endl;
	for(int j = 0; j < 5000; j++)
	{
		int v1, v2;
		v1 = rand() % 5000;
		v2 = rand() % 5000;
		swap(a[v1], a[v2]);
	}
	cout << a << endl;

}