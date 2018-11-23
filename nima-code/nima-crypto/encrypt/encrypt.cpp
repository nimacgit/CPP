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
string word;
string dis;
string otext;








void iread()
{
	ifstream i;
	stringstream is;
	int f=0;
	i.open("text",ios::binary);
	itext.clear();
	icode.clear();
	word.clear();
	dis.clear();
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



void crypt()
{
	otext=itext;
	string s;
	s.clear();
	int b=0;
	for(int j=0,k=1;j<otext.length();j++)
	{
		otext[j]+=2;
		if(j%(stoi(dis))==b)
		{
			s.clear();
			for(int l=0;l<stoi(word);l++)
			{
				if(k==icode.length()-1)
					k=1;
				s+=icode[k];
				k++;
			}
			otext.insert(j+1,s);
			j+=stoi(word);
			for(int h=0;h<stoi(word);h++)
			{
				b++;
				if(b==stoi(dis))
					b=0;
			}
		}
	}
}


void write()
{
	ofstream o;
	o.open("ctext",ios::out);
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



int main()
{
	iread();
	cout<<"text: "<<endl<<itext<<endl<<"code: "<<icode<<endl;
	crypt();
	cout<<otext<<endl;
	write();

}
