#include <bits/stdc++.h>

using namespace std;



const int maxn = 50 * 1000;
int d[maxn + 100];
int n;
int alpha[26][26];
string names[maxn + 100];
string s;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> names[i];
	s = names[0]; 
	alpha[s[0] - 'a'][s[s.length() - 1] - 'a'] = 1;
	d[0] = 0;
	for(int i = 1; i < n; i++)
	{
		s = names[i];
		d[i] = d[i - 1];
		int first = s[0] - 'a';
		int last = s[s.length() - 1] - 'a';
		int temp = alpha[last][last];
		if(alpha[last][first] != 0)
			temp = alpha[last][last] = max(alpha[last][first] + 1, alpha[last][last]);
		d[i] = max(d[i], temp);
		for(int j = 0; j < 26; j++)
		{
			if(alpha[j][first] != 0)
				alpha[j][last] = max(alpha[j][last], alpha[j][first] + 1);
		}
	}
	cout << d[n - 1] << endl;
}	
