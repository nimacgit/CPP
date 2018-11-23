#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair

using namespace std;

typedef pair<int, int> pie;
const int maxn = 1000 * 100;
int sum[3][maxn + 100];
int n, q;

int main()
{
	ifstream in("bcount.in", ios::in);
	in >> n >> q;
	sum[1][0] = sum[0][0] = sum[2][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		in >> temp;
		sum[1][i] = sum[1][i - 1];
		sum[0][i] = sum[0][i - 1];
		sum[2][i] = sum[2][i - 1];
		sum[temp - 1][i]++;
	}
	ofstream out("bcount.out", ios::out);
	for(int i = 0; i < q; i++)
	{
		int temp, temp1;
		in >> temp >> temp1;
		out << sum[0][temp1] - sum[0][temp - 1] << " " << sum[1][temp1] - sum[1][temp - 1] << " " << sum[2][temp1] - sum[2][temp - 1] << endl;
	}
	out.close();
	return 0;
}
