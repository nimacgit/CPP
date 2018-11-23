#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int maxn = 1000 * 1000 * 10;
bool notprimes[maxn + 10];
vector<int> factor[maxn + 10];
vector<int> prime;
map < pair<int,int>, int > mymap;

void findprime()
{
	notprimes[1] = true;
	for(int i = 2; i <= maxn; i++)
	{
		if(!notprimes[i])
		{
			factor[i].push_back(i);
			if(i * 2 <= maxn)
				prime.push_back(i);
			for(int j = 2; j * i <= maxn; j++)
			{
				notprimes[i * j] = true;
				if(factor[i * j].size() < 3)
					factor[i * j].push_back(i);
			}
		}
	}
}

int main()
{
	findprime();
	cout << " be " << endl;
	for(int i = maxn; i >= 0; i--)
	{
		if(factor[i].size() == 2)
		{
			int p = min(factor[i][1], factor[i][0]);
			int q = max(factor[i][1], factor[i][0]);
			if(mymap.find(make_pair(p,q)) == mymap.end())
				mymap[make_pair(p,q)] = i;
			else
				if(mymap[make_pair(p,q)] < i)
					mymap[make_pair(p,q)] = i;
		}
	}
	long long sum = 0;
	while(!mymap.empty())
	{
		sum += (mymap.begin())->second;
		mymap.erase(mymap.begin());
	}
	cout << sum << endl;

}