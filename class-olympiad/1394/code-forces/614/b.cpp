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


int n;
const int maxn = 1000 * 1000 * 100;
int nums = 0;
char a[1000 * 100 + 100];
string numi = "1";

int main()
{
	cin >> n;	
	bool flag = true;
	bool zero = false;
	for(int i = 0; i < n; i++)
	{
		flag = true;
		scanf("%s", a);
		if(!zero)
		{		
			int as = strlen(a);
			int one = 0;
			if(as == 1 && a[0] == '0')
			{
				zero = true;
			}
			else
			{
				for(int j = 0; j < as; j++)
				{
					if(a[j] > '1' || (a[j] == '1' && one == 1))
						flag = false;
					if(a[j] == '1')
						one++;
				}
				if(!flag)
				{
					numi[0] = a[0];
					for(int j = 1; j < as; j++)
						numi += a[j];
				}
				else
				{
					nums += as - 1;
				}
			}
		}
	}
	if(zero)
		cout << 0 << endl;
	else
	{
		cout << numi;
		for(int i = 0; i < nums; i++)
			cout << 0;
		cout << endl;
	}

}	
