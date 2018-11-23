#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 * 100;
string text, pat;
int next[maxn];


void findnext()
{
	next[0] = -1;
	next[1] = 0;
	for(int i = 2; i < pat.size(); i++)
	{
		int j = i - 1;
		while(j >= 0 && pat[next[j] + 1] != pat[i])
			j = next[j] + 1;
		if(pat[j + 1] == pat[i])
			pat[i] = next[j] + 1;
		pat[i] = 0;
	}
}


vector<int> kmp()
{
	

}



int main()
{
	

}
