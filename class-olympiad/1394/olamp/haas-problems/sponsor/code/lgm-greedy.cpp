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

const double eps=1e-8;
const ld leps=1e-14;

vector <pie> list;
const int MN=10000;
int n,m;
pie point[MN];
bool cm[MN];
int color[MN];
int del[MN];
int dis(pie & a,pie & b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
bool cmp(const pie & a,const pie & b)
{
	if (dis(point[a.first],point[a.second])!=dis(point[b.first],point[b.second]))
		return dis(point[a.first],point[a.second])<dis(point[b.first],point[b.second]);
	return a<b;
}
int go()
{
	memset(cm,0,sizeof(cm));
	memset(del,0,sizeof(del));
	for (int i=0;i<list.size();i++)
	{
		int a=list[i].first,b=list[i].second;
		if (del[a] || del[b]) continue;
		if (cm[color[a]]==1 && cm[color[b]]==1) 
			return dis(point[a],point[b]);
		if (cm[color[a]]==1)
			del[b]=1,cm[color[b]]=1;
		else if (cm[color[b]]==1)
			del[a]=1,cm[color[a]]=1;
		else
		{
			if (rand()%2)
				del[b]=1,cm[color[b]]=1;
			else
				del[a]=1,cm[color[a]]=1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	srand(701*n);
	for (int i=0;i<n;i++)
		cin>>point[i].first>>point[i].second>>color[i],color[i]--;
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++)
		list.push_back(pie(i,j));
	sort(list.begin(),list.end(),cmp);
//	for (int i=0;i<list.size();i++)
//		cerr<<list[i].first<<" "<<list[i].second<<" "<<dis(point[list[i].first],point[list[i].second])<<endl;
	int res=0;
	for (int i=0;i<200;i++)
		smx(res,go());
	cout<<res<<endl;
	return 0;
}
