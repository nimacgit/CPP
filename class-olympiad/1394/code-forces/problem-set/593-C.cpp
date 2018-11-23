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
const int maxn = 1000;
int x[maxn], y[maxn];
int ansx, ansy, kx, ky, zx, zy, n;
string f, g;

string ss(int a)
{
	if(a == 0)
		return "0";
	string s;
	while(a > 0)
	{
		s += a%10 + '0';
		a /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	cin >> n;
	for(int i = 0, r; i < n; i++)
		cin >> x[i] >> y[i] >> r;
	for(int i = 1; i < n; i++, f+= '(', g+= '(');
	f += ss(x[0]);
	g += ss(y[0]);
	ansx = x[0];
	ansy = y[0];
	kx = ky = 0;
	for(int i = 1; i < n; i++)
	{
		zx = (abs(x[i] - kx*i - ansx) / 2);
		zy = (abs(y[i] - ky*i - ansy) / 2);
		if(kx * i + ansx > x[i])	
		{
			f += "-(" + ss(zx) + "*(abs((t-" + ss(i - 1) + "))+(t-" + ss(i-1) + "))))";
			kx -= zx*2;
			ansx += zx*(2*i - 2);

		}
		else if(kx * i + ansx < x[i])
		{
			f += "+(" + ss(zx) + "*(abs((t-" + ss(i - 1) + "))+(t-" + ss(i-1) + "))))";
			kx += zx*2;
			ansx -= zx*(2*i - 2);
		}
		else
			f += "+0)";
		if(ky * i + ansy > y[i])	
		{
			g += "-(" + ss(zy) + "*(abs((t-" + ss(i - 1) + "))+(t-" + ss(i-1) + "))))";
			ky -= zy*2;
			ansy += zy*(2*i - 2);

		}
		else if(ky * i + ansy < y[i])
		{
			g += "+(" + ss(zy) + "*(abs((t-" + ss(i - 1) + "))+(t-" + ss(i-1) + "))))";
			ky += zy*2;
			ansy -= zy*(2*i - 2);
		}
		else
			g += "+0)";
	}	
	cout << f << endl;
	cout << g << endl;

}
