#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <set>


using namespace std;


const int maxn = 1000 * 1000 * 10;
set<int> myset;
int n;
int k;

int d(int num)
{
	int temp = 0;
	while(num)
	{
		temp += num % 10;
		num /= 10;
	}
	return temp;
}

void find()
{
	for(int i = 1; i <= n; i++)		
		myset.insert
}


int main()
{
	cin >> n;
	find();
	cout << myset.size() << endl;
	cin >> k;
/*	for(int i = 0; i < k; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d ", finded[temp - 1]);
	}
*/	
}
