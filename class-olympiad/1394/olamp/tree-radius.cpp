#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define mp make_pair
#include <deque>
#include <map>

using namespace std;


typedef pair<int, int> pii;
const int maxn = 300;
vector <int> myvec[maxn + 100];
bool seen[maxn + 100];
int h[maxn + 100];
bool out[maxn + 100];
int n, k;
bool adj[maxn + 100][maxn + 100];
int parent[maxn + 100];
map<int,pii>::iterator it;


int bfs(int v, bool chooz)
{
//	cerr << "bfs " <<  v << " : ";
	deque <pair<int,pii> > mydeq;
	parent[v] = -1;
	for(int j = 0; j < n; j++)
        {
        	if(!out[j])
                	seen[j] = false;
                else
                        seen[j] = true;
        }
	queue<int> myque;
	stack<int> keeper;
	myque.push(v);
	keeper.push(v);
	h[v] = 0;
	int last = v;
	while(!myque.empty())
	{
		int u = myque.front();
		last = u;
		seen[u] = true;
		myque.pop();
		for(int i = 0; i < myvec[u].size(); i++)
		{
			if(!seen[myvec[u][i]])
			{	
				parent[myvec[u][i]] = u;
				h[myvec[u][i]] = h[u] + 1;
//				cerr << myvec[u][i] << " ";
				myque.push(myvec[u][i]);
				keeper.push(myvec[u][i]);
			}
		}
	}
	int u = keeper.top();
	keeper.pop();
//	cerr << " KEe " << u << "  " << keeper.top() << " " << h[u] <<"  " << h[keeper.top()]  << endl;
	if(chooz && (h[(keeper.top())] == h[u]))
		return v;
	else if(!chooz)
	{
		pii save;
		map<int,pii> mymap;
		mymap[u] = mp(u,1);
		deque<int> fathers;
		fathers.push_back(u);
//		cerr << " father " << " ";
		while(!keeper.empty() && h[keeper.top()] == h[u])
		{
			fathers.push_back(keeper.top());
//			cerr << keeper.top() << " ";
			mymap[keeper.top()] = mp(keeper.top(), 1);			
			keeper.pop();
		}
		while(mymap.size() > 1)
		{
//			cerr << " bo " << mymap.size() << endl;
//			for(int i = 0; i < fathers.size(); i++)
//				cerr << mymap[fathers[i]].first << "  " << mymap[fathers[i]].second << "  ";
//			cerr << endl;
//			cerr << "ok " << endl;
			for(int i = 0; i < fathers.size(); i++)
			{
//				cerr << " i " << i << "  ";
				int pos = fathers.front();
				fathers.pop_front();
				i--;
				save = mymap[pos];
//				cerr << " check ";
				if(parent[pos] != -1)
				{
//					cerr << " secondcheck ";
					it = mymap.find(parent[pos]);
					if(it != mymap.end())
					{
//						cerr << " third ";
						pii orginal = mymap[parent[pos]];
//						cerr << " mymap.second  " << mymap[parent[pos]].second << " save  " << save.second << endl;
						if(orginal.second > save.second)
						{
							save.second += orginal.second;
							mymap[parent[pos]] = save;
						}
						else
						{
							mymap[parent[pos]].second += save.second;
						}
//						cerr << "mymap.second  " <<  mymap[parent[pos]].second << endl;
						mymap.erase(mymap.find(pos));
					}
					else
					{
//						cerr << " 4th ";
						fathers.push_back(parent[pos]);
						i++;
						mymap.erase(mymap.find(pos));
						mymap[parent[pos]] = save;
					}
				}
			}
//			cerr << endl;
		}
//		cerr << "finish  " << fathers.front() << "  " << mymap[fathers.front()].first << endl;
		return mymap[fathers.front()].first;
	}
//	cerr << "  =  " << last << endl;
	return last;
}

int dis(int v)
{
	 for(int j = 0; j < n; j++)
        {
                if(!out[j])
                        seen[j] = false;
                else
                        seen[j] = true;
        }
	queue<int> myque;
        myque.push(v);
	h[v] = 0;
        int last = v;
        while(!myque.empty())
        {
                int u = myque.front();
                last = u;
                seen[u] = true;
                myque.pop();
                for(int i = 0; i < myvec[u].size(); i++)
                {
                        if(!seen[myvec[u][i]])
                        {
                                myque.push(myvec[u][i]);
				h[myvec[u][i]] = h[u] + 1;
                        }
                }
        }
        return h[last];


}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		myvec[x].push_back(y);
		myvec[y].push_back(x);
		adj[x][y] = adj[y][x] = true;
	}
	for(int i = 0; i < k; i++)
	{
		for(int o = 0; o < n; o++)
	        {
	                if(!out[o])
	                {                      
				int v = bfs(o, false);
				v = bfs(v, true);
				out[v] = true;
				o = n;
			}
		}
	}
//	for(int i = 0; i < n; i++)
//		cerr << i << "  " << out[i] << endl; 
	for(int i = 0; i < n; i++)
	{
		if(!out[i])
		{
			int v = bfs(i, false);
			cout << dis(v) << endl;
			return 0;
		}
	}

}

