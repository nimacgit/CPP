#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1000 + 4;
int n, a[maxn], tempn;
vector<int> v;
vector <string> s;
vector<string> logs;
vector<int> logsn;
string temp;
vector<string> final;
vector<int> finaln;

int main()
{
	cin >> n;
	int maximum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> temp >> tempn;
		logs.push_back(temp);
		logsn.push_back(tempn);
		bool flag = false;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == temp)
			{
				flag = true;
				v[j] += tempn;
			}
		}
		if(!flag)
		{
			s.push_back(temp);
			v.push_back(tempn);
		}
	}
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] > v[maximum])
			maximum = i;
	}
	//cerr << v[maximum] << endl;
	for(int i = 0; i < logsn.size(); i++)
	{
		temp = logs[i];
		tempn = logsn[i];
		bool flag = false;
		for(int j = 0; j < final.size(); j++)
		{
			if(final[j] == temp)
			{
				flag = true;
				finaln[j] += tempn;
				if(finaln[j] >= v[maximum] && v[j] == v[maximum])
				{
					cout << final[j] << endl;
					return 0;
				}
			}
		}
		if(!flag)
		{
			final.push_back(temp);
			finaln.push_back(tempn);
			//cout << " be "  << i << "  " << finaln.size() << endl;
			if(finaln[finaln.size() - 1] >= v[maximum] && v[finaln.size() - 1] == v[maximum])
			{
				cout << final[finaln.size() - 1] << endl;
				return 0;
			}
		}
	}
}