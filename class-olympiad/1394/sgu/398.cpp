#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a[50 + 2][50 + 2];
vector<int> fv[52];
vector<int> ff;

int main()
{
	int n, x;
	cin >> n >> x;
	for(int i = 1, temp; i <= n; i++)
	{
		cin >> temp;
		for(int j = 0, f; j < temp; j++)
		{
			cin >> f;
			a[i][f] = 1;
			fv[i].push_back(f);
		}
	}
	for(int i = 0; i < fv[x].size(); i++)
	{
		int frnd = fv[x][i];
		for(int j = 0; j < fv[frnd].size(); j++)
		{
//			cout << " j= " << j << " i= " << i << " frnd " << frnd << " a[fv[frnd][j]][x] " << a[fv[frnd][j]][x] << " ff " << fv[frnd][j] << endl;
			if(a[(fv[frnd][j])][x] == 0 && fv[frnd][j] != x)
				ff.push_back(fv[frnd][j]);
		}
	}
	sort(ff.begin(),ff.begin() + ff.size());
	for(int i = 1; i < ff.size(); i++)
		if(ff[i] == ff[i - 1])
		{
			ff.erase(ff.begin() + i - 1);
			i--;
		}
	cout << ff.size() << endl;
	for(int i = 0; i <  ff.size(); i++)
	{
		cout<< ff[i] << endl;
	}

}