#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include <sstream>



using namespace std;

string itext;
string icode;
string otext;
string dis;
string word;







void iread()
{
	ifstream i;
	stringstream is;
	int f=0;
	i.open("ctext",ios::binary);
	itext.clear();
	icode.clear();
	is << i.rdbuf();
	string s;
	s=is.str();
	for(int j=0;j<s.length();j++)
	{
		if(s[j]=='#')
			f++;
		else
		{
			if(f==0)
				itext+=s[j];
			else
				if(f==1)
					icode+=s[j];
				else
					if(f==2)
						word+=s[j];
					else
   						if(f==3)
							dis+=s[j];
		}
	}
	itext=itext.substr(0,itext.length()-1);
	word=word.substr(1,word.length()-2);
	dis=dis.substr(1,dis.length()-2);
}



void decrypt()
{
	otext=itext;
	for(int j=0,k=1;j<otext.length();j+=stoi(dis))
	{
		for(int l=0;l<stoi(word);l++)
		{
			if(k==icode.length()-1)
				k=1;
			if(otext[j+1]==icode[k])
			{
				otext.erase(j+1,1);
				k++;
			}
		}
	}
}



void write()
{
	ofstream o;
	o.open("text",ios::out);
	for(int i=0;i<otext.length();i++)
	{
		o<<otext[i];
	}
	o<<endl<<"#"<<endl;
	for(int i=1;i<icode.length()-1;i++)
		o<<icode[i];
	o<<endl<<"#"<<endl;
	for(int i=0;i<word.length();i++)
		o<<word[i];
	o<<endl<<"#"<<endl;
	for(int i=0;i<dis.length();i++)
		o<<dis[i];
	o<<endl;
} 

void rev()
{
	for(int i=0;i<otext.length();i++)
		otext[i]-=2;
}

int main()
{
	iread();
	cout<<"text: "<<endl<<itext<<endl<<"code: "<<icode<<endl;
	decrypt();
	rev();
	cout<<otext<<endl;
	write();
}
