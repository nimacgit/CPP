#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;


const int maxn  = 100;
int n, t;

int main()
{
	cin >> n >> t;
	if(n == 1 && t == 10)
	{
		cout << -1 << endl;
		return 0;
	}
	if(t == 10)
	{
		cout << t;
		for(int i = 2; i < n; i++)
			printf("%s", "0");
	}
	else
	{
		cout << t;
		for(int i = 1; i < n; i++)
			printf("%s", "0");
	}
	cout << endl;
}
