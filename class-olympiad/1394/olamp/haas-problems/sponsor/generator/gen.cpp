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
#include "testlib.h"
#include <cassert>
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
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;
const int MN=10000,MAX=1000*1000;
int n,m,tot;
int color[MN];
int w[MN];
int all[MN];
set <pie> mark;
int makecolor()
{
	int t=rnd.next(1,tot);
	for (int i=0;i<m;i++) if (t<=w[i]) return i;
	else
		t-=w[i];
}
int main(int argc,char ** argv)
{
	ios_base::sync_with_stdio(false);
	registerGen(argc,argv);
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;
	assert(m<=int(n/2));
	for (int i=0;i<n;i++) all[i]=i;
	shuffle(all,all+n);
	memset(color,-1,sizeof(color));
	for (int i=0;i<m;i++)
		color[all[2*i]]=color[all[2*i+1]]=i;
	for (int i=0;i<m;i++) w[i]=rnd.next(1,100),tot+=w[i];
	for (int i=0;i<n;i++) if (color[i]==-1)
		color[i]=makecolor();
	for (int i=0;i<n;i++)
	{
		int x=rnd.next(-MAX,MAX),y=rnd.next(-MAX,MAX);
		while (mark.find(pie(x,y))!=mark.end())
			x=rnd.next(-MAX,MAX),y=rnd.next(-MAX,MAX);
		mark.insert(pie(x,y));
		cout<<x<<" "<<y<<" "<<color[i]+1<<endl;
	}
	return 0;
}
