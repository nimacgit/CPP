#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



using namespace std;

const int maxn = 1000 * 10;
bool notprime[maxn + 100];
vector <int> prime;
vector <int> s_prime;
int minim[maxn + 10];
bool ismade[maxn + 10];
int parent[maxn + 10];
int n;
const int inf = 1000000;

void find()
{
	for(int i = 2; i <= maxn; i++)
	{
		if(!notprime[i])
		{
			prime.push_back(i);
			for(int j = 2; i * j <= maxn; j++)
				notprime[i * j] = true;
		}
	}
	for(int i = 0; i < prime.size() && prime[i] <= prime.size() && prime[prime[i]] <= maxn; i++)
		s_prime.push_back(prime[prime[i] - 1]);

}

int findmin()
{
	minim[0] = 0;
	parent[0] = -1;
	for(int i = 1; i <= maxn; i++)
	{
		minim[i] = inf;
		parent[i] = -1;
		for(int j = 0; j < s_prime.size() && i >= s_prime[j]; j++)
		{
			if(minim[i - s_prime[j]] + 1 < minim[i])
			{
				minim[i] = minim[i - s_prime[j]] + 1;
				parent[i] = i - s_prime[j];
			}
		}
	}
}


vector <int> finded;
void print(int a)
{
	if(a != 0)
	{
		finded.push_back(a - parent[a]);
		//cerr << " say " << finded.back() << endl;
		print(parent[a]);
	}
}

int main()
{
	find();
	cin >> n;
	//cerr << s_prime.size() << endl;
	fill(parent, parent + maxn + 10, -1);
	for(int i = 0; i < s_prime.size(); i++)
	{
		minim[s_prime[i]] = 1;
		parent[s_prime[i]] = -1;
		ismade[s_prime[i]] = true;
	}
	//cerr << " test2 " << endl;
	findmin();
	int check = minim[n];
	//cerr << "test3 " << endl;
	if(check >= inf)
	{
		cout << 0 << endl;
		return 0;
	}
	else
		print(n);
	//cerr << minim[n] << " " << finded.size() << endl;
	cout << minim[n] << endl;
	//cerr << " test4 " << endl;
	sort(finded.begin(), finded.end());
	for(int i = finded.size() - 1; i >= 0; i--)
		cout << finded[i] << " ";
	cout << endl;
	//cerr << " test " << parent[9] << endl;

}