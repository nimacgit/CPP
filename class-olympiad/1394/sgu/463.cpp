#include <iostream>
#include <string>



using namespace std;


const int maxn = 100;
int city[maxn + 10][maxn + 10];
int n, m;
string s;
string path;
pair <int, int> rot;
int rotat = 0;
long long sat = 0;
bool use[maxn + 10][maxn + 10];
int x = 0, y = 0;



void move()
{
	if(x + rot.first >= 0 && x + rot.first <= n && y + rot.second >= 0 && y + rot.second <= m)
	{
		if(rotat == 0 || rotat == 1)
		{
			sat += city[x + rot.first][y + rot.second];
			if(!use[x + rot.first][y + rot.second])
			{
				use[x + rot.first][y + rot.second] = true;
				city[x + rot.first][y + rot.second] /= 2;
			}
		}
		else
		{
			sat += city[x][y];
			if(!use[x][y])
			{
				use[x][y] = true;
				city[x][y] /= 2;
			}
		}
		switch(rotat)
		{
			case 0:
				sat += city[x + rot.first + 1][y + rot.second];
				if(!use[x + rot.first + 1][y + rot.second])
				{
					use[x + rot.first + 1][y + rot.second] = true;
					city[x + rot.first + 1][y + rot.second] /= 2;
				}
				break;
			case 1:
				sat += city[x + rot.first][y + rot.second + 1];
				if(!use[x + rot.first][y + rot.second + 1])
				{
					use[x + rot.first][y + rot.second + 1] = true;
					city[x + rot.first][y + rot.second + 1] /= 2;
				}
				break;
			case 2:
				sat += city[x + 1][y];
				if(!use[x + 1][y])
				{
					use[x + 1][y] = true;
					city[x + 1][y] /= 2;
				}
				break;
			case 3:
				sat += city[x][y + 1];
				if(!use[x][y + 1])
				{
					use[x][y + 1] = true;
					city[x][y + 1] /= 2;
				}
				break;
		}
		x = x + rot.first;
		y = y + rot.second;
	}
}


void changdir(char c)
{
	if(c == 'R')
		rotat++;
	else
		rotat--;
	rotat = (rotat + 4 ) % 4;
	switch(rotat)
	{
		case 0:
			rot = make_pair(0, 1);
			break;
		case 1:
			rot = make_pair(1, 0);
			break;
		case 2:
			rot = make_pair(0, -1);
			break;
		case 3:
			rot = make_pair(-1, 0);
			break;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < maxn + 10; i++)
	{
		if(i > 0  && i <= n)
		{
			cin >> s;
			for(int j = 0; j < maxn + 10; j++)
				if( j > 0 && j <= m)
					city[i][j] = s[j - 1] - '0';
		}
		else
			for(int j = 0; j < maxn + 10; j++)
				city[i][j] = 0;
			
	}
	cin >> path;
	rot = make_pair(0, 1);
	for(int i = 0; i < path.length(); i++)
	{
		if(path[i] == 'M')
			move();
		else
			changdir(path[i]);
		//cerr << sat << "  " << x << "  " << y << endl;
	}
	cout << sat << endl;
}