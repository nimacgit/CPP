#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const long long maxn = 1000 * 1000;
const int max2 = 64;
bool check[maxn];
string biner = "000001";
int number = 100000;
vector <string> paterns;



void find()
{
	for(long long i = 2; i < maxn; i++)
		if(!check[i])
		{
			cout << i << endl;
			for(long long j = 2; i * j < maxn; j++)
				check[i * j] = true;
		}
}

void binerplus()
{
	biner[5]++;
	for(int i = 5; biner[i] > '1' && i > 0; i--)
	{
		biner[i] -= 2;
		biner[i - 1]++;
	}
}

pair<int, int> primenumber(int pat)
{
	int co = 0;
	int temp = number;
	int biger = 1;
	int minimprime = 10000000;
	for(int i = 0; i < 10; i++)
	{
		biger = 1;
		//cout << number << "  " << pat << "  " << temp << " first " ;
		for(int j = 5; j >= 0; j--)
		{
			if(paterns[pat][j] == '1')
			{
				temp -= ((temp / biger) % 10) * biger;
				temp += (biger * i);
			}
			biger *= 10;
		}
		//cout << temp << endl;
		if(!check[temp])
		{
			if(temp < minimprime)
				minimprime = temp;
			co++;
		}
	}
	if(minimprime > maxn / 10)
		return make_pair(co, minimprime);
	else
		return make_pair(-1, -1);
}


int main()
{
	find();
	int minimum = 100000000;
	string minimpat;
	for(int i = 1; i < max2; i++)
	{
		paterns.push_back(biner);
		binerplus();

	}
	while(number < 1000000)
	{
		for(int i = 0; i < paterns.size(); i++)
		{
			if(!check[number])
			{
				pair <int, int> temp = primenumber(i);
				if(temp.first == 8)
				{
					if(temp.second < minimum)
					{
						minimum = temp.second;
						minimpat = paterns[i];
					}
				}	
			}
		}
		number++;
	}
	cout << minimum << "  " << minimpat << endl;


	
}
