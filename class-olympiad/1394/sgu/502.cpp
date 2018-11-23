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

const int maxn = 18;
vector <long long> alfa;
long long ten = 1, num;
int digit[10], n = 0;
vector <bool> patern[10];
bool used[maxn];
bool flag[10];


int main()
{
	for(int i = 0; i < 10; i++)
		digit[i] = 0;
	cin >> num;
	while(num > 0)
	{
		digit[num % 10]++;
		num /= 10;
		n++;
	}
	for(int i = 0; i < n - 1; i++)
	{
		alfa.push_back(ten);
		ten *= 10;
	}
	int co = 0;
	for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < n - digit[i] - co; j++)
			patern[i].push_back(0);
		for(int j = 0; j < digit[i]; j++)
			patern[i].push_back(1);
		co += digit[i];
	}
	flag[1] = true;
	while(flag[1])
	{
		flag[2] = true;
		while(flag[2])
		{
			flag[3] = true;
			while(flag[3])
			{
				flag[4] = true;
				while(flag[4])
				{
					flag[5] = true;
					while(flag[5])
					{
						flag[6] = true;
						while(flag[6])
						{
							flag[7] = true;
							while(flag[7])
							{
								flag[8] = true;
								while(flag[8])
								{
									flag[9] = true;
									while(flag[9])
									{
										
										flag[9] = next_permutation(patern[9].begin(), patern[9].end());			
									}	
									flag[8] = next_permutation(patern[8].begin(), patern[8].end());
								}
								flag[7] = next_permutation(patern[7].begin(), patern[7].end());
							}		
							flag[6] = next_permutation(patern[6].begin(), patern[6].end());
						}
						flag[5] = next_permutation(patern[5].begin(), patern[5].end());
					}	
					flag[4] = next_permutation(patern[4].begin(), patern[4].end());
				}
				flag[3] = next_permutation(patern[3].begin(), patern[3].end());
			}		
			flag[2] = next_permutation(patern[2].begin(), patern[2].end());
		}
		flag[1] = next_permutation(patern[1].begin(), patern[1].end());
	}


	
}