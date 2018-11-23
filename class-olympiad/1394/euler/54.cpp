#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool player[2][4][14];
vector <int> plvec[2][4];
string s;

int choose(char c)
{
	switch (c)
	{
		case 'C':
		return 0;
		case 'H':
		return 1;
		case 'D':
		return 2;
		case 'S':
		return 3;
	}
}

void addcart(int a)
{
	switch (s[0])
	{
		case 'A' :
		player[a][choose(s[1])][13] = true;
		break;
		case 'J':
		player[a][choose(s[1])][10] = true;
		break;
		case 'Q':
		player[a][choose(s[1])][11] = true;
		break;
		case 'K':
		player[a][choose(s[1])][12] = true;
		break;
		case 'T':
		player[a][choose(s[1])][9] = true;
		break;
		default :
		player[a][choose(s[1])][s[0] - '0' - 1] = true;
	}
}

bool hasrf(int a)
{
	for(int j = 0; j < 4; j++)
	{
		bool flag = true;
		for(int i = 9; i < 14 && flag; i++)
		{
			if(!player[a][j][i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			return true;
	}
	return false;
}

int hassf(int a)
{
	for(int i = 0; i < 4; i++)
	{
		if(plvec[a][i].size() == 5)
		{
			for(int j = 0; j < 4; j++)
				if(plvec[a][i][j] != plvec[a][i][j + 1] - 1)
					return -1;
			return plvec[a][i][4];
		}
	}	
}

int hasfok(int a)
{	
	for(int i = 13; i > 0; i--)
	{
		bool flag = true;
		for(int j = 0; j < 4; j++)	
		{
			if(player[a][j][i] != true)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			return i;
	}
	return -1;
}

int hasfh(int a)
{
	int val3 = -1, val2 = -1;
	int maximum = -1;
	for(int i = 13; i > 0; i--)
	{
		int sum = 0;
		for(int j = 0; j < 4; j++)
		{
			if(player[a][j][i])
				sum++;
		}
		if(sum == 3)
			val3 = i;
		else if(sum == 2)
			val2 = i;
	}
	if(val2 != -1 && val3 != -1)
		return val3 * 100 + val2;
	return -1;
}

int hasflush(int a)
{
	for(int i = 0; i < 4; i++)
		if(plvec[a][i].size() == 5)
			return i;
	return -1;
}


int checkflush(int a, int b)
{
	for(int j = 4; j >= 0; j--)
		if(plvec[0][a][j] != plvec[1][b][j])
			return plvec[1][b][j] - plvec[0][a][j];
	return 0;
}


int hass(int a)
{
	int sum = 0, maxindex = -1;
	for(int i = 1; i < 14; i++)
	{
		bool flag = false;
		for(int j = 0; j < 4; j++)
		{
			if(player[a][j][i])
			{
				flag = true;
				maxindex = i;
				sum++;
				break;
			}
		}
		if(!flag)
			sum = 0;
	}
	if(sum == 5)
		return maxindex;
	return -1;
}


int hastok(int a)
{
	int card = 0;
	for(int i = 13; i >= 0; i--)
	{
		card = 0;
		for(int j = 0; j < 4; j++)
			if(player[a][j][i])
				card++;
		if(card == 3)
			return i;
	}
	return -1;
}


int hastp(int a)
{
	int sum = 0, ans = 0;
	for(int i = 13; i > 0; i--)
	{
		int same = 0;
		for(int j = 0; j < 4; j++)
			if(player[a][j][i])
				same++;
		if(same == 2)
		{
			sum++;
			ans = ans * 100 + i;
		}
	}
	if(sum == 2)
		return ans;
	return -1;
}

int hasop(int a)
{
	
	for(int i = 13; i > 0; i--)
	{
		int same = 0;
		for(int j = 0; j < 4; j++)
			if(player[a][j][i])
				same++;
		if(same == 2)
			return i;
	}
	return -1;
}

int hashc(int a)
{
	for(int i = 13; i > 0; i--)
	{
		for(int j = 0; j < 4; j++)
		{
			if(player[a][j][i])
				return i;
		}
	}
	return -1;
}




bool firstwin()
{
	if(hasrf(0) != hasrf(1))
		return hasrf(0) < hasrf(1);
	if(hassf(0) != hassf(1))
		return hassf(0) < hassf(1);
	if(hasfok(0) != hasfok(1))
		return hasfok(0) < hasfok(1);
	if(hasfh(0) != hasfh(1))
		return hasfh(0) < hasfh(1);
	if(hasflush(0) != -1 || hasflush(1) != -1)
	{
		int temp1 = hasflush(0), temp2 = hasflush(1);
		if(temp1 == -1 )
			return true;
		else if(temp2 == -1)
			return false;
		else 
		{
			int comp = checkflush(temp1, temp2);
			if(comp < 0)
				return false;
			else if(comp > 0)
				return true;
		}
	}
	if(hass(0) != hass(1))
		return hass(0) < hass(1);
	if(hastok(0) != hastok(1))
		return hastok(0) < hastok(1);
	if(hastp(0) != hastp(1))
		return hastp(0) < hastp(1);
	if(hasop(0) != hasop(1))
		return hasop(0) < hasop(1);
	if(hashc(0) != hashc(1))
		return hashc(0) < hashc(1);
}

void reset()
{
	for(int i = 0; i < 4; i++)
	{
		plvec[0][i].clear();
		plvec[1][i].clear();
		for(int j = 0; j < 14; j++)
			player[0][i][j] = player[1][i][j] = false;
	}
}




int main()
{
	int co = 0;
	for(int i = 0; i < 1000; i++)
	{
		reset();
		for(int g = 0; g < 5; g++)
		{
			cin >> s;
			addcart(0);
		}
		for(int g = 0; g < 5; g++)
		{
			cin >> s;
			addcart(1);
		}
		for(int z = 0; z < 2; z++)
		{
			for(int j = 0; j < 4; j++)
			{
				for(int k = 1; k < 14; k++)
				{
					if(player[z][j][k])
					{
						plvec[z][j].push_back(k);
					}
				}
			}
		}
		//cout << " i ==  " << i << endl;
		if(!firstwin())
		{
			co++;
			cout << i + 1 << endl;
		}
		//cout << "last i == " << i << endl;
	}
	cout << co << endl;
}