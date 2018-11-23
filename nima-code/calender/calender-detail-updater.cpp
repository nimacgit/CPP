#include <iostream>
//#include <time.h>
#include <ctime>
#include <fstream>
//#include "convertor.cpp"
#include <string>
#include <vector>

using namespace std;

class Detail
{
public:
	string pday;
	string date;
	string data;
	int day;
	int month;
	int year;
};
//gets calender file and seperate datas and update the first day of calender
int uptonow()
{
	ifstream in;
	in.open("calender",ios::in);
	string s;
	Detail det[60];
	int flag=1;
	int today=0;
	for(char c;!in.eof();)
	{
		in>>c;
		if(c==':')
		{
			det[today].pday=inter(s);
			flag=1;
			s="";
		}
		else
			if(c=='#')
			{
				det[today].date=rev(s)+' ';
				s="";
				flag=1;
			}
			else
				if(c=='!')
				{
					today++;
					det[today].data=s;
					s="";
					flag=1;
				}
				else
					if(c=='|')
						flag=0;
						else
							if(flag==1)
								s+=c;
	}
	for(int i=1;i<=today;i++)
	{
		indate(det[i].day,det[i].month,det[i].year,det[i].date);
		swap(det[i].day,det[i].year);
		//cout<<det[i].day<<endl;
		//cout<<i<<" "<<det[i].day<<" "<<det[i].date<<" "<<det[i].data<<endl;	
	}
	in.close();
	ofstream ot;
	ot.open("calender",ios::out);
	int difrentday=deffrent(det[1].day,det[1].month,det[1].year);
	//cout<<difrentday<<endl;
	int now=findtoday();
	for(int i=2+difrentday;i<=today+1;i++)
	{
		ot<<"!"<<days(now)<<":"<<rev(det[i-1].date)<<"#"<<det[i].data<<endl<<endl<<endl;	
		now++;
		if(now==8)
		{
			ot<<"|_____________________________|"<<endl<<endl;
			now=1;
		}
	}
	ot.close();

}