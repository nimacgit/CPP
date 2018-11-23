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
int x[3], y[3];
bool fx= false, fy = false;

int main()
{
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	if(x[0] == x[1] && x[1] == x[2])
		cout << 1 << endl;
	else if(y[0] == y[1] && y[1] == y[2])
		cout << 1 << endl;
	else if(x[0] != x[1] && x[1] != x[2] && x[0] != x[2] && y[0] != y[1] && y[1] != y[2] && y[2] != y[0])
			cout << 3 << endl;
	else
	{
		for(int i = 0; i < 3; i++)
			for(int j = i + 1; j < 3; j++)
			{
				if(x[i] == x[j])
					fx = true;
				if(y[i] == y[j])
					fy = true;
			}
		if(fx || fy)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
}
