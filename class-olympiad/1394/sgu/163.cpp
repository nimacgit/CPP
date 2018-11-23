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


const int maxn = 100;
int n, p;
int a[maxn + 10];
vector <int> pos;
vector <int> neg;
long long sum = 0;


int power(int a, int b)
{
	int sum = 1;
	for(int i = 0; i < b; i++)
		sum *= a;
	return sum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> p;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(power(a[i], p) > 0)
			sum += power(a[i], p);
	}
	cout << sum << endl;



	
}