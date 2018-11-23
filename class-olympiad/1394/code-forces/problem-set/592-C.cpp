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
long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}


long long t, w, b, gc = 0, ans = 0, scm = 0;

int main()
{
	cin >> t >> w >> b;
	if(w == b)
	{
		cout << "1/1" << endl;
		return 0;
	}
	if(log(w/ gcd(w,b)) + log(b) > log(t) + 1)
	{
		ans = min(min(b, w) - 1, t);
		gc = gcd(ans , t);
		cout << ans / gc << '/' << t / gc << endl;
		return 0;
	}
	scm = (w / gcd(w, b)) * b;
	if(t < scm)
	{
		ans = min(t, min(b, w) - 1);
		cout << ans / gcd(ans, t) << '/' << t / gcd(ans, t) << endl;
		return 0;
	}	
	t -= scm;
	ans += min(w, b) - 1;
	ans += t / ((b / gcd(b, w)) * w) * min(b, w);
	gc = t % scm;
	ans += min(gc + 1, min(b, w));
	t += scm;
	cerr << ans << " " << gc << endl;
	long long temp = gcd(t, ans);
	cout <<  ans / temp  << "/" << t / temp << endl;
}
