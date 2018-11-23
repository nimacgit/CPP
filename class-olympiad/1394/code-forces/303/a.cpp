#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100 + 2;
int n;
bool cars[maxn];
int matr[maxn][maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin >> matr[i][j];
			if(i != j)
			{
				if(matr[i][j] == 1)
					cars[i] = true;
				if(matr[i][j] == 3)
					cars[i] = cars[j] = true;
				if(matr[i][j] == 2)
					cars[j] = true;
			}
		}
	int sum = 0;
	vector<int> v;
	for(int i = 0; i < n; i++)
		if(!cars[i])
		{
			v.push_back(i + 1);
			sum++;
		}
	cout << sum << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";


}