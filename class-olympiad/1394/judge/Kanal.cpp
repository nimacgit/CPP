#include <iostream>
#include <vector>


using namespace std;

const int maxn = 1000 * 1000 + 3;
vector<int> v[maxn];

int r, n, maxt = 0, mint = 0, rate;

int main()
{
	cin >> n >> r;
	for(int i = 0, b , t; i < n; i++)
	{
		cin >> b >> t;
		if(t == 0)
		{
			cout << "no" << endl;
			return 0;
		}
		if(t > b)
			rate = 0;
		else
			rate =  b / t;
		if(maxt < rate)
			maxt = rate;
		if(mint > rate)
			mint = rate;
		v[(int)rate].push_back(b);
		v[(int)rate].push_back(t);

	}	
	//cout << "e " << endl;
	long long sumt = 0, sumbit = 0;
	for(int i = mint; i <= maxt; i++)
	{
		for(int j = 0; j < v[i].size(); j += 2)
		{
			sumt += v[i][j + 1];
			sumbit += v[i][j];
			if(sumt * r < sumbit)
			{
				cout << "no" << endl;
				return 0;
			}
		}
	}	
	cout << "yes" << endl;
}