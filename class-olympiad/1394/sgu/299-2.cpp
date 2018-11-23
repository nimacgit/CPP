#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 2;
string so[1000 + 10][1000 + 10];
string s[maxn];
string b;
string maxs;

void sort_s(int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1 - i; j++)
			if(s[j].length() > s[j + 1].length())
				swap(s[j], s[j + 1]);
	int siz = s[0].length();
	int index = 0;
	for(int i = 1; i < n; i++)
	{
		if(s[i].length() != siz)
		{
			sort(s + index, s + i);
			index = i;
			siz = s[i].length();
		}
	}
}

bool istri(int i, int j, int k)
{
	if(so[i][j].length() == 0)
	{
		b = s[i];
		for(int l = 0; l < s[j].length(); l++)
		{
			if(l >= b.length())
			{
				b += s[j][l];
			}
			else
				if(b[l] > 47)
					b[l] += s[j][l] - 48;
				else
					b[l] += s[j][l];
			if(b[l] > 9 + 48)
			{
				b[l] -= 10;
				if(l + 1 == b.length())
					b += '1';
				else
					b[l + 1] += 1;
			}
		}
		so[i][j] = b;
	}
	if(so[i][j].length() < s[k].length())
		return false;
	//cout << b << endl;
	if(s[k].length() == so[i][j].length())
	{
		//cout << " b= " << b << " s[k] " << s[k] << endl;
		reverse(s[k].begin(), s[k].end());
		reverse(so[i][j].begin(), so[i][j].end());
		if(s[k] >= so[i][j])
		{
			reverse(so[i][j].begin(), so[i][j].end());
			reverse(s[k].begin(), s[k].end());

			return false;
		}
		reverse(so[i][j].begin(), so[i][j].end());
		reverse(s[k].begin(), s[k].end());

	}
	return true;
}


int main()
{
	int maxindex = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort_s(n);
	for(int i = 0; i < n; i++)
	{
		reverse(s[i].begin(), s[i].end());
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(istri(i, j, j + 1) == true)
			{
				return 0;
			}
		}
	}
	cout << "0 0 0" << endl;
}