#include <bits/stdc++.h>
#define S second
#define F first
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<int,int> pie;

const int maxn = 1e6 + 10;
int lim = 200, n;
long double a[maxn];

long double check(long double x)
{
	long long difmin, difmax;
	difmin = difmax = a[0];
	for(int i = 1; i < n; i++)
	{
		if(difmin > a[i] - (long double)i * x)
			difmin = a[i];
		if(difmax < a[i] - (long double)i * x)
			difmax = a[i];
	}
	long double mid = (difmax + difmin)/2.00;
	long double ans = 0;
	long double pos = mid;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > pos)
			ans = max(ans, a[i] - pos);
		else
			ans = max(ans, pos - a[i]);
		pos += x;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	long double s = 0, e = 1e9;
	e /= n;
	e++;
	bool flag = false;
	for(int i = 0; i < lim; i++)
	{
		long double t1 = (2.0*s + e)/3.00, t2 = (s+2.0*e)/3.00;
		long double ans1 = check(t1), ans2 = check(t2);
		cerr << "check " << ans1 << " " << ans2 << " " << s << " " << e << endl;
		if(ans1 > ans2)
		{
			s = ans1;
			flag = true;
		}
		else
			e = ans2;
	}
	if(!flag)
		s = e;
	cout << fixed << setprecision(4);
	cout << s << endl;
}
