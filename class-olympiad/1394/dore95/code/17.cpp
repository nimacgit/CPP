#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;
const int maxn = 1e5 + 100;
long long a[maxn];
int n, k;
long long choose[maxn][2];
long long mo = 1e9 + 7;
long long ans = 0;
long long pw(long long num, long long p)
{
	if(p == 0)
		return 1;
	long long temp = pw(num, p / 2);
	temp *= temp;
	temp %= mo;
	if(p % 2)
		temp *= num;
	return (temp % mo);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int f = k/2, s = k - k/2 - 1;
	choose[f][0] = 1;
	for(int i = f + 1; i <= n; i++)
		choose[i][0] = (((choose[i - 1][0] * i) % mo) * pw(i - f, mo - 2))%mo;
	choose[s][1] = 1;
	for(int i = s + 1; i <= n; i++)
		choose[i][1] = (((choose[i - 1][1] * i) % mo) * pw(i - s, mo - 2))%mo;
	for(int i = f + 1; i <= n && n - i >= s; i++)
		ans += (((a[i - 1] * choose[i - 1][0]) % mo) * choose[n - i][1]) % mo;
	cout << ans%mo << endl;
}
