#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;

int main()
{
	for(int i = 5; i < 100; i++)
	{
		cerr << i << " : "; 
		int sum = 0;
		for(int j = 1; j < i; j++)
		{
			cerr << i % j << " ";
			sum += i % j;
		}

		cerr << " sum " << sum  << endl;
	}
}
