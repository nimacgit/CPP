#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1100 * 1000;

bool mark[maxn];
vector<int> myque;
int h[maxn];
bool s[maxn];
int n;


int makeint()
{
	long long int a = 0;
	for(int i = 0; i < 20; i++)
		a = a * 2 + s[i];
	return int(a);
}

int change(int j, int a)
{
	for(int i = max(0, j - 1); i <= min(j + 1, 19); i++)
		a = a ^ (1 << i);
	return a;
}


void bfs(int z)
{
	h[z] = 0;
	myque.push_back(z);
	mark[z] = true;
	for(int i = 0; i < (int)myque.size(); i++)
		{
			int v = myque[i];
			for(int j = 0; j < 20; j++)
			{
				int u = change(j, v);
				//cerr << u << endl;
				if(!mark[u])
				{
					//cerr << " check " << endl;
					if(u == 0)
					{
						cout << h[v] + 1 << endl;
						return;
					}
					myque.push_back(u);
					mark[u] = true;
					h[u] = h[v] + 1;
				}
			}
		}
}




int main()
{
	cin >> n;
	for(int w = 0; w < n; w++)
	{
		char temp;
		for(int i = 0 ; i < 20; i++)
			cin >> s[i];
		for(int i = 0; i < myque.size(); i++)
			mark[myque[i]] = false;
		myque.clear();
		int z = makeint();
		if(z == 0)
			cout << 0 << endl;
		else
			bfs(z);
	}
}