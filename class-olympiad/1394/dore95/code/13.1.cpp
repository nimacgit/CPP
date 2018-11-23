#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int dp[2][maxn];
vector<pie> mv;
int n;

void makedp()
{
	dp[0][0] = -1;
	mv.push_back(mp(a[0], 0));
	for(int i = 1; i < n - 1; i++)
	{
		while(!mv.empty() && mv[mv.size() - 1].F < a[i])
			mv.pop_back();
		if(mv.empty())
			dp[0][i] = -1;
		else
			dp[0][i] = mv[mv.size() - 1].S;
		mv.push_back(mp(a[i], i));
	}
	mv.clear();
	dp[1][n - 2] = n - 1;
	mv.push_back(mp(a[n - 2], n - 2));
	for(int i = n - 3; i >= 0; i--)
	{
		while(!mv.empty() && mv[mv.size() - 1].F < a[i])
			mv.pop_back();
		if(mv.empty())
			dp[1][i] = n - 1;
		else
			dp[1][i] = mv[mv.size() - 1].S;
		mv.push_back(mp(a[i], i));	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int maxi = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		if(b[i] > b[maxi])
			maxi = i;
	}
	for(int i = maxi + 1; i < n; i++)
		a[i - maxi - 1] = b[i];
	for(int i = 0; i < maxi; i++)
		a[i + n - maxi - 1] = b[i];
	makedp();
	long long ans = n - 1;
	for(int i = 0; i < n -1; i++)
		ans += dp[1][i] - dp[0][i] - 2;
	cout << ans << endl;
}
