#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 + 2;
vector <int> list[maxn];
bool check[maxn][maxn];
bool mark[maxn];
vector<int> myque;
int h[maxn];


int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i = 0; i < m; i++)
	{	
		cin >> x >> y;
		x--,y--;
		list[x].push_back(y);
		list[y].push_back(x);
	}
	cout << "2bakhshi bud..." << endl;
	return 0;
	cout << "gashtam nabud nagard nis..." << endl;
}