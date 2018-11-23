#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 150;
vector <int> tri;
vector <int> squ;
vector <int> pent;
vector <int> hexa;
vector <int> hep;
vector <int> octa;
bool tris[100];
bool squs[100];
bool pents[100];
bool hexas[100];
bool heps[100];
bool octas[100];
bool use[100];

int twoL(int a)
{
	return a / 100;
}
int twoR(int a)
{
	return a % 100;
}


int main()
{
	int temp;
	for(int i = 1; i < maxn; i++)
	{
		temp = i * (i - 1) / 2;
		if(temp > 999 && temp < 10000)
		{
			tri.push_back(temp);
			tris[twoR(temp)] = true;
		}
	}
	for(int i = 0 ; i < 100; i++)
		use[i] = false;
	for(int i = 0; i < maxn; i++)
	{
		temp = i * i;
		if(temp > 999 && temp < 10000)
		{
			if(tris[twoL(temp)])
			{
				use[twoL(temp)] = true;
				squ.push_back(temp);
				squs[twoR(temp)] = true;
			}
		}
	}
	for(int i = 0 ; i < 100; i++)
	{
		tris[i] = use[i];
		use[i] = false;
	}
	for(int i = 0; i < maxn; i++)
	{
		temp = i * (3 * i - 1) / 2;
		if(temp > 999 && temp < 10000)
		{
			if(squs[twoL(temp)])
			{
				use[twoL(temp)] = true;
				pent.push_back(temp);
				pents[twoR(temp)] = true;
			}
		}
	}
	for(int i = 0; i < maxn; i++)
	{
		temp = i * (2 * i - 1);
		if(temp > 999 && temp < 10000)
		{
			if(pents[twoL(temp)])
			{
				hexa.push_back(temp);
				hexas[twoR(temp)] = true;
			}
		}
	}
	for(int i = 0; i < maxn; i++)
	{
		temp = i * (5 * i - 3) / 2;
		if(temp > 999 && temp < 10000)
		{
			if(hexas[twoL(temp)])
			{
				hep.push_back(temp);
				heps[twoR(temp)] = true;
			}
		}
	}
	for(int i = 0; i < maxn; i++)
	{
		temp = i * (3 *i - 2);
		if(temp > 999 && temp < 10000)
		{
			if(heps[twoL(temp)])
			{
				octa.push_back(temp);
				octas[twoR(temp)] = true;
			}
		}
	}
	for(int i = 0; i < tri.size(); i++)
	{
		temp = tri[i];
		if(octas[twoL(temp)])
		{
			cout << temp << endl;
			tri.clear();
			tri.push_back(temp);
		}
	}




}