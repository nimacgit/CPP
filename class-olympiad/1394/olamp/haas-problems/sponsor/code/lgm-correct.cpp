//In the name of Allah
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <map>
//#include <climits>
//#include <list>

using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define fl endl<<flush

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}


/*
ifstream fin(".in");
ofstream fout(".out");
#define cin fin
#define cout fout
*/

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
//typedef complex<double> point;
const double eps=1e-8;
const ld leps=1e-14;
const int MN=4000+100;
vector <int> list[MN],rlist[MN];;
vector <int> colors[MN];
pie point[MN];
bool mark[MN];
int com[MN];
int cc;
vector <int> ft;
int n,m;
int fix(int a)
{
	if (a>=0) return a;
	return n-a;
}
void dfs(int a)
{
	mark[a]=1;
	for (int i=0;i<list[a].size();i++) if (!mark[list[a][i]])
		dfs(list[a][i]);
	ft.push_back(a);
}
void rdfs(int a)
{
	mark[a]=1;
	com[a]=cc;
	for (int i=0;i<rlist[a].size();i++) if (!mark[rlist[a][i]])
		rdfs(rlist[a][i]);
}
int dis(pie & a,pie & b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int add(int a,int b)
{
	list[fix(-a)].push_back(fix(b));
	list[fix(-b)].push_back(fix(a));
	rlist[fix(b)].push_back(fix(-a));
	rlist[fix(a)].push_back(fix(-b));
}
bool av(int a)
{
	for (int i=0;i<=2*n;i++) list[i].clear(),rlist[i].clear();
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<colors[i].size();j++)
			for (int j2=j+1;j2<colors[i].size();j2++)
				add(colors[i][j],colors[i][j2]);
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (dis(point[i],point[j])<a)
		add(-i,-j);
	memset(mark,0,sizeof(mark));
	ft.clear();
	for (int i=1;i<=2*n;i++) if (!mark[i])
		dfs(i);
	memset(mark,0,sizeof(mark));
	cc=0;
	for (int i=2*n-1;i>=0;i--) if (!mark[ft[i]])
		rdfs(ft[i]),cc++;
	for (int i=1;i<=n;i++) if (com[i]==com[fix(-i)])
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int c;
		cin>>point[i].first>>point[i].second>>c; c--;
		colors[c].push_back(i);
	}
//	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++)
//		cerr<<i<<" - "<<j<<" = "<<dis(point[i],point[j])<<endl;
	int s=0,e=5000000;
	int res=0;
	while (s<=e)
	{
		int m=(s+e)/2;
		if (av(m))
			res=m,s=m+1;
		else
			e=m-1;
	}
	cout<<res<<endl;
	return 0;
}
