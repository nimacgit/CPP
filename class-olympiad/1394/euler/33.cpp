#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int gc(int a, int b)
{
	if(b == 0)
		return a;
	return gc(b, a % b);
}

int main()
{
	vector <double> sours;
	vector <double> makhs;
	for(double i = 1; i < 10; i ++)	
	{
		for(double j = i; j < 10; j ++)
		{
			for(double bi = 0; bi < 10; bi++)
			{
				for(double bj = 0; bj < 10; bj++)
				{
					if(bi != bj || i != j)
					{
						/*if(bi == bj)
						{
							double sour = i * 10 + bi;
							double makh = j * 10 + bj;
							if(j != 0 && (double(sour / makh) == double(i / j)))
							{
								cout << " a " << i << "  " << j << "  " << bi << "  " << bj << endl;
								sours.push_back(sour);
								makhs.push_back(makh);
							}
						}
						*/
						if(bi == j)
						{
							double sour = i * 10 + bi;
							double makh = j * 10 + bj;
							if(bj != 0 && (double(sour / makh) == double(i / bj)))
							{
								cout << " b " << i << "  " << j << "  " << bi << "  " << bj << endl;
								sours.push_back(sour);
								makhs.push_back(makh);
							}
						}	
						if(i == j)
						{
							double sour = i * 10 + bi;
							double makh = j * 10 + bj;
							if(bj != 0 && (double(sour / makh) == double(bi / bj)))
							{
								cout << " c " << i << "  " << j << "  " << bi << "  " << bj << endl;
								sours.push_back(sour);
								makhs.push_back(makh);
							}
						}
						if(i == bj)
						{
							double sour = i * 10 + bi;
							double makh = j * 10 + bj;
							if(j != 0 && (double(sour / makh) == double(bi / j)))
							{
								cout << " d " << i << "  " << j << "  " << bi << "  " << bj << endl;
								sours.push_back(sour);
								makhs.push_back(makh);
							}
						}	
					}
				}
			}
		}
	}
	for(int i = 0; i < sours.size(); i++)
		cout << sours[i] << "  " << makhs[i] << "  " << sours[i] / makhs[i]  << endl;
	cout << gc(5228496, 3872960 * 5) << endl;
}