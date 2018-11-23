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
const int maxn =  500 * 1000 + 100;
int n;


int main()
{
	cin >> n;
	if(n % 2 == 0)
	{
		for(int i = 1; i < n; i+=2)
			printf("%d ", i);
		for(int i = n - 1; i > 0; i-=2)
			printf("%d ", i);
		for(int i = 2; i <= n; i+= 2)
			printf("%d ", i);
		for(int i = n - 2; i > 0; i-= 2)
			printf("%d ", i);
		printf("%d", n);
	}
	else
	{
		for(int i = 1; i <= n; i+=2)
			printf("%d ", i);
		for(int i = n - 2; i > 0; i-=2)
			printf("%d ", i);
		printf("%d ", n);
		for(int i = 2; i < n; i+= 2)
			printf("%d ", i);
		for(int i = n - 1; i > 0; i-= 2)
			printf("%d ", i);
	}
	printf("\n");

}
