#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;

const int delta = 29123;
bool mark[delta + 3];
string rope;
bool use[delta + 3];
vector<string> v;

void addnum(int a)
{
	int temp = a;
	string b;
	b.clear();
	while(temp > 0)
	{
		b.insert(b.begin(), temp % 10 + '0');
		temp /= 10;
	}
	v.push_back(b);
}

int main()
{
	mark[1] = true;
	int sum = 0;
	for(int i = 2; i <= delta; i++)
	{
		if(!mark[i])
		{
			for(int j = 2; i * j <= delta; j++)
				mark[i * j] = true;
			if(i > 7)
			{
				addnum(i);
				sum++;
			}
			else
				mark[i] = true;
		}
	}
	cout << sum << endl;
	rope = v[0];
	v.erase(v.begin());
	int last;
	cout << v.size() << endl;
	bool change = true;
	for(int k = 0; change; k++)
	{
		//cout << k << "  ";
		change = false;
		for(int i = v.size() - 1; i >= 0; i--)
		{
			//cout << i << endl;
			last = rope.length() - 1;
			if(rope[last] == v[i][0])
			{
				//cout << " 1 first " << rope << "  ";
				rope.erase(rope.begin() + last);
				rope += v[i];
				v.erase(v.begin() + i);
				change = true;
				//cout << rope << endl;
			}
			else
			{
				if(rope[0] == v[i][v[i].length() - 1])
				{
					//cout << " 2 firt " << rope << " ";
					rope.erase(rope.begin());
					rope = v[i] + rope;
					v.erase(v.begin() + i);
					change = true;
					//cout << rope << endl;
				}
			}
		}
	}
	cout << v.size() << endl;
	cout << rope.length() << endl;

}