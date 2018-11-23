#include <iostream>
#include <vector>
#include <cstring>

#define SZ(x) ((int)x.size())
#define X first
#define Y second 
#define PB push_back 
#define MP make_pair 

using namespace std;
typedef long long ll;
const int D = 1e9 + 7;

vector <ll> f[2];
ll n0 = 1e12, n1 = 1e12, n2 = 17, n3 = 17;

ll doJob(ll x, bool subtask){
	if(!subtask)
		return x * (x - 1) / 2;
	
	ll sum = x;
	ll p = 2;	
	while(p <= x){
		sum += x / p * (p >> 1);
		p <<= 1;
	}
	return sum;
}

ll sum_degree(ll l, ll r, bool subtask){
   	return doJob(r, subtask) - doJob(l, subtask);
} 

ll get_par(ll x, bool subtask){
	int h = lower_bound(f[subtask].begin(), f[subtask].end(), x) - f[subtask].begin();
	if(h == 0) return -1;
	if(h == 1) return 1;
	ll l = f[subtask][h - 2], r = f[subtask][h - 1];
	if(sum_degree(l, l + 1, subtask) + r >= x) return l + 1;
	ll down = l + 1, up = r;
	while(up - down > 1){
		ll mid = (down + up) / 2;
		if(sum_degree(l, mid, subtask) + r >= x)
			up = mid;
		else
			down = mid;
	}
	return up;
}

pair<ll, ll> get_sub_tree(ll l, ll r, bool subtask){
	int h = lower_bound(f[subtask].begin(), f[subtask].end(), r) - f[subtask].begin();
	if(h >= (subtask ? 18 : 9) ) return {-1, -1};
	ll x = f[subtask][h - 1], y = f[subtask][h];
	l = sum_degree(x, l - 1, subtask) + y + 1;
	r = sum_degree(x, r, subtask) + y;
	return {l, r};
}

int main(){
	f[0].PB(1); f[0].PB(2);
	for(int i = 2; i < 10; ++i)
		f[0].PB(f[0][i - 1] + sum_degree(f[0][i - 2], f[0][i - 1], 0));

	f[1].PB(1); f[1].PB(2);
	for(int i = 2; i < 22; ++i)
		f[1].PB(f[1][i - 1] + sum_degree(f[1][i - 2], f[1][i - 1], 1));

	ll sum = n0;
	while(get_par(n0, 0) != -1){
		n0 = get_par(n0, 0);
		sum += n0;
		sum %= D;
	}
	cout << "subtask 0 : " << sum << endl;
	sum = n1;
	while(get_par(n1, 1) != -1){
		n1 = get_par(n1, 1);
		sum += n1;
		sum %= D;
	}
	cout << "subtask 1 : " << sum << endl;
	ll l = n2, r = n2;
	sum = 0;
	while(get_sub_tree(l, r, 0).X != -1){
		pair<ll, ll> tmp = get_sub_tree(l, r, 0);
		sum += (r - l + 1) * (r + l) / 2;
		sum %= D;
		l = tmp.X, r = tmp.Y;
	}
	cout << "subtask 2 : " << sum << endl;
	l = n3, r = n3;
	sum = 0;
	while(get_sub_tree(l, r, 1).X != -1){
		pair<ll, ll> tmp = get_sub_tree(l, r, 1);
		if((r - l + 1) % 2 == 0)
			sum += (r - l + 1) / 2  % D * (r + l) % D;
		else
			sum += (r + l) / 2  % D * (r - l + 1) % D;	
		sum %= D;
		l = tmp.X, r = tmp.Y;
	}
	cout << "subtask 3 : " << sum << endl;
	return 0;
}
