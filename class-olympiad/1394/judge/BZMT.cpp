#include <iostream>

using namespace std;

const int maxn = 10000 + 2;
int d[2][maxn];
string s1, s2;
int n, m;

void bzm()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				d[i % 2][j] = d[(i - 1) % 2][j - 1] + 1;
			else
				d[i % 2][j] =  max(d[(i - 1) % 2][j], d[i % 2][j - 1]);
			//cout << d[i % 2][j] << " ";
		}
		//cout << endl;
	}
}

int main()
{
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	d[0][0] = d[1][0] = d[0][1] = 0;
	bzm();
	cout << d[n % 2][m] << endl;

}