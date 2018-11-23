#include <iostream>
#include <vector>

using namespace std;

const long long maxn = 100 + 3;
vector <long long> v, person;
bool net[maxn][maxn];
long long sources, users;


void set(long long i)
{
	v.clear();
	for(long long j = 1; j <= sources; j++)
		if(net[i][j] == true)
			v.push_back(j);
}

int main()
{
	cin >> sources >> users;
	for(long long i = 1, num; i <= users; i++)
	{
		cin >>  num;
		for(long long j = 1, temp; j <= num; j++)
		{
			cin >> temp;
			net[i][temp] = true;
		}
	}
	long long sum = 0;
	for(long long i = 1; i <= users; i++)
	{
		set(i);
		person.clear();
		person.push_back(i);
		while(v.size() > 0)
		{	
			/*
			cout << v.size() << endl;
			for(int z = 0; z < v.size(); z++)
			{
				cout << v[z] << " ";
			}
			cout << endl;
			*/
			for(long long j = i + 1; j <= users; j++)
			{
				if(net[j][v[0]] == true)
				{
					person.push_back(j);
					for(long long k = 1; k < v.size(); k++)
					{
						if(net[j][v[k]] == false)
						{
							v.erase(v.begin() + k);
							k--;
						}
					}
				}
				else
				{
					for(long long k = 1; k < v.size(); k++)
						if(net[j][v[k]] == true)
						{
							v.erase(v.begin() + k);
							k--;
						}
				}
			}
			for(long long j = 0; j < v.size(); j++)
			{
				for(long long k = 0; k < person.size(); k++)
					net[person[k]][v[j]] = false;
			}
			sum++;
			set(i);
		}
	}
	cout << sum << endl;
	
}