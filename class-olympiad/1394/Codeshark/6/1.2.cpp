#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pie;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

const int maxn = 1e7;
bool notp[maxn];
vector<int> p;
int n = 1e6;
long long sum = 0;
int mo = 34019;


void sieve()
{
	for(int i = 2; i < maxn; i++)
		if(!notp[i])
		{
			p.push_back(i);
			for(int j = 2; i * j < maxn; j++)
				notp[i * j] = true;
		}	

}

long long two[30];

long long et(int i, int k)
{
	long long ans = 1;
	int temp = i;
	while(temp > 1)
	{
		ans *= i;
		temp--;
	}
	temp = i - k;
	while(temp > 1)
	{
		ans /= temp;
		temp--;
	}
	temp = k;
	while(temp > 1)
	{
		ans /= temp;
		temp--;
	}
	cerr << " et " << ans << endl;
	return ans;
}

long long pw(long long a, long long p)
{
	if(p == 0)
		return 1;
	long long ans = pw(a, p / 2) % mo;
	ans *= ans;
	ans %= mo;
	if(p % 2 == 1)
		ans *= a;
	cerr << " pw " << ans << endl;
	return ans % mo;
}

long long g(int a)
{
	vector<int> pnum;
	vector<int> pr;
	vector<int> ch;
	int  one = 0;
	for(int i = 0; a > 1; i++)
	{
		if(a % p[i] == 0)
		{
			pr.push_back(p[i]);
			pnum.push_back(0);
			ch.push_back(0);
			while(a % p[i] == 0)
			{
				a /= p[i];
				pnum[pnum.size() -1]++;
			}

		}
	}
	long long ans = 0;
	ans = 1;
	cerr << "Test1 " << ans << endl;
	cerr << " test2 " << ans << endl;
	for(int i = 0; i < two[pr.size()] - 1; i++)
	{
		ch[0]++;
		one++;
		int k = 0;
		while(ch[k] > 1)
		{
			ch[k] = 0, ch[k + 1]++;
			one--;
			k++;
		}
		cerr << " testttt " << endl;
		cerr << endl;
		for(int j = 0; j <= pr.size() - one; j++)
			ans = (ans + (et(pr.size() - one, j)%mo) * (two[pr.size() - one - j]) % mo)%mo;
		ans /= 2;
		ans--;
		for(int j = 0; j < pr.size(); j++)
			if(ch[j] == 1)
				ans = (ans * pw(pr[j], pnum[j])) % mo;
	}
	cerr << "  test3 " << ans << endl;
	return ans;
}



int main()
{
	sieve();
	two[0] = 1;
	for(int i = 1; i < 25; i++)
		two[i] = two[i - 1] * 2;
	cout << g(2) << endl;
//	for(int i = 2; i <= n; i++)
//		sum = (sum + g(i)) % mo;
	cout << sum << endl;
}
