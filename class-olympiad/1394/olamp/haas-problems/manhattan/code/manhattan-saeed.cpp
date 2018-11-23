#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

const int MAXQ = 2*1000+10;

bool mark[2*MAXQ];
int n,m,cnt_q,comp,tot;
int where[2*MAXQ];
pair<int,bool> qx[2*MAXQ],qy[2*MAXQ];
vector <int> order;
vector <int> adj[2*MAXQ],back[2*MAXQ];

int getv (int x) { return 2*x; }
int getnv(int x) { return 2*x+1; }

void add_clause (int a, int b){
	adj [a].push_back(b^1);
	back[b^1].push_back(a);
	adj [b].push_back(a^1);
	back[a^1].push_back(b);
}

void dfs (int v){
	mark[v] = true;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp])
			dfs(temp);
	}
	order.push_back(v);
}

void dfs_back (int v){
	where[v]= comp;
	mark [v]= true;
	for (int i=0; i<(int)back[v].size(); i++){
		int temp = back[v][i];
		if (!mark[temp])
			dfs_back(temp);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &cnt_q);
	tot = comp = 0;
	assert(2<=n && n<=1000);
	assert(2<=m && m<=1000);
	assert(1<=cnt_q && cnt_q<=1000);
	for (int i=0; i<4*cnt_q; i++){
		qx[i] = qy[i] = pair<int,bool>(-1,false);
		adj[i].clear();
		back[i].clear();
	}
	for (int i=0; i<cnt_q; i++){
		int x,y,xx,yy; scanf("%d%d%d%d", &x, &y, &xx, &yy);
		assert(0<x && 0<xx && x<=n && xx<=n);
		assert(0<y && 0<yy && y<=m && yy<=m);
		x--; y--; xx--; yy--;
		if (x==xx && y==yy) continue;
		if (x==xx){
			qx[tot] = pair<int,bool>(x, y<yy);
			add_clause(getv(tot),getv(tot));
			tot++;
		}else if (y==yy){
			qy[tot] = pair<int,bool>(y, x<xx);
			add_clause(getv(tot),getv(tot));
			tot++;
		}else{
			qx[tot] = pair<int,bool>(x, y<yy);
			qy[tot] = pair<int,bool>(yy,x<xx);
			tot++;
			qy[tot] = pair<int,bool>(y, x<xx);
			qx[tot] = pair<int,bool>(xx,y<yy);
			tot++;
			add_clause(getv(tot-2),getv(tot-1));
		}
	}
	for (int i=0; i<tot; i++)
		for (int j=i+1; j<tot; j++){
			if (qx[i].first==qx[j].first && qx[i].first!=-1 && qx[i].second != qx[j].second)
				add_clause(getnv(i), getnv(j));
			else if (qy[i].first==qy[j].first && qy[i].first!=-1 && qy[i].second != qy[j].second)
				add_clause(getnv(i), getnv(j));
		}
	order.clear();
	memset(mark,0,sizeof mark);
	for (int i=0; i<2*tot; i++) if (!mark[i])
		dfs(i);
	memset(mark,0,sizeof mark);
	for (int i=(int)order.size()-1; i>=0; i--) if (!mark[order[i]]){
		dfs_back(order[i]);
		comp++;
	}
	bool flag = false;
	for (int i=0; i<tot; i++) if (where[2*i] == where[2*i+1]){
		puts("No\n");
		flag = true;
		break;
	}		
	if (!flag)
		puts("Yes");
	return 0;
}
