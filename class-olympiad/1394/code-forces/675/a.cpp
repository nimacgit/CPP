#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

long long a, b, c, n;

int main()
{
	 cin >> a >> b >> c;
	 if(c == 0)
	 {
		 if(a == b)
			 cout << "YES" << endl;
		 else
			 cout << "NO" << endl;
		 return 0;
	 }
	 long long f = 1;
	 if(c < 0)
		f = -1;
	 if(f*(b + c - a) >= 1 && (b + c - a) % c == 0)
		 cout << "YES" << endl;
	 else
		 cout << "NO" << endl;

}
