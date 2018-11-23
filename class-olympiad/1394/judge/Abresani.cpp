#include <iostream>
#include <vector>

#define PB push_back

using namespace std;

const int maxn = 100 + 2;
vector <int> list[maxn];
int n, sum = 0;
bool mark[maxn];


void DFS(int v)
{
	mark[v] = true;
	for(int i = 0; i < list[v].size(); i++)
	{
		if(!mark[list[v][i]])
		{
			sum++;
			DFS(list[v][i]);
		}
	}

}


int main()
{
	cin >> n;
	for(int i = 0, temp; i < n; i++)		
	{
		for(int j = 0; j < n; j++)
		{
			cin >> temp;
			if(temp == 1)
				list[i].PB(j);
		}
	}
	DFS(0);
	cout << sum << endl;
}