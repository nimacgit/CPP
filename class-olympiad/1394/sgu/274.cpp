#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int suf = 10,pre = 10,let = 10,sym = 10,dom = 10,add = 10;

bool isletter(char c)
{
	if((c > 64 && c < 91) || (c > 96 && c < 123))
		return true;
	else
	{
		let = 0;
		return false;
	}
}
bool issymbol(char c)
{
	if( (isletter(c) || (c > 47 && c < 58) || c == '_' || c == '-'))
		return true;
	else
	{
		sym = 0;
		return false;
	}
}
bool isdomain(char *start, char *end)
{
	if(end - start > 3 || end - start < 2)
		return false;
	if(!(isletter(start[0]) && isletter(start[1])))
	{
		return false;
	}
	if(end - start == 3)
		if(!(isletter(start[2])))
		{
			return false;
		}
	return true;
}
char* isaddress(char *start, char *end)
{
	bool flag = false;
	char *pos = NULL;
	for(; start < end ; start++)
		if(*start == '@')
			if(!flag)
			{
				flag = true;
				pos = start;
			}
			else
				return NULL;
	return pos;
}

bool isprefix(char *start, char *end)
{
	if(end - start < 1)
		return false;
	char * temp = end - 1;
	int dotcount = 0;
	if(*temp == '.')
		return false;
	for(;temp >= start; temp--)
	{
		if(*temp == '.')
			dotcount ++;
		else
			dotcount = 0;
		if(temp == start)
			if(*temp == '.')
				return false;
		if(dotcount > 1)
			return false;
		if(!(issymbol(*temp)))
			if(*temp != '.')
				return false;
	}
	return true;
}

bool issuffix(char *start, char *end)
{
	char * temp = start;
	int dot;
	for(;temp < end; temp++)
		if(*temp == '.')
		{
			dot = temp - start; 
		}		
	if(!isdomain(start + dot + 1, end))
	{
		dom = 2;
		suf = 2;
		return false;
	}
	if(!isprefix(start, start + dot))
	{
		pre = -1;
		suf = -1;
		return false;
	}
	return true;
}

string s;
int n;


int main()
{
	scanf("%d", &n);
	getline(cin, s);
	int at,dot;
	bool Isok = true;
	while(n)
	{
		n--;
		getline(cin, s);
		Isok = true;
		if(isaddress(&s[0], &s[s.length()]) == NULL)
			Isok = false;
		else
			at = isaddress(&s[0], &s[s.length()]) - &s[0];
		if(Isok)
		{
			if(issuffix(&s[at + 1], &s[s.length()]) && isprefix(&s[0], &s[at]))
				Isok = true;
			else
				Isok = false;
		}
		if(Isok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	//	cout << suf << " pre " << pre << " let " << let << " sym " << sym << " dom " << dom << " add " << add << endl;

	}
	
}
