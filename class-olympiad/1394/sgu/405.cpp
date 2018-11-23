#include <iostream>

using namespace std;

const int maxn = 100 + 3;
int n, m, gols1, gols2, pred1, pred2;
int persons[maxn];

bool win()
{
	if(gols2 > gols1 && pred2 > pred1)
		return true;
	if(gols2 < gols1 && pred2 < pred1)
		return true;
	if(gols1 == gols2 && pred1 == pred2)
		return true;
	return false;
}
bool diff()
{
	if(gols2 - gols1 == pred2 - pred1)
		return true;
	else
		return false;
}
bool score1()
{
	if(gols1 == pred1)
		return true;
	return false;
}
bool score2()
{
	if(gols2 == pred2)
		return true;
	return false;
}



int main()
{
	cin >> n >> m;

	for(int i = 1 ; i <= m; i++)
	{
		cin >> gols1 >> gols2;
		for(int j = 1; j <= n; j++)
		{
			cin >> pred1 >> pred2;
			if(win())
				persons[j] += 2;
			if(diff())
				persons[j] += 3;
			if(score2())
				persons[j]++;
			if(score1())
				persons[j]++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << persons[i] << " ";
	cout << endl;
}