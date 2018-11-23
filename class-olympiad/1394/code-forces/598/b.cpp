#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <set>


using namespace std;

const int maxn = 100 * 1000;
int q, l, r, k;
string s;
string t;

int main()
{
	cin >> s;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &l, &r, &k);
		t = s;
		k = k % (r - l + 1);
		int si = (r - l + 1);
		for(int j = l - 1; j < r; j++) 
		{
			if(j - k  < l - 1)
				t[j] = s[j + si - k];
			else
				t[j] = s[j - k];
		}
		s = t;
	}
	cout << s << endl;
}
