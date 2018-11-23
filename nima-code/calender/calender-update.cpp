#include <iostream>
//#include <time.h>
#include <ctime>
#include <fstream>
#include "convertor.cpp"
#include <string>
#include <vector>
#include "calender-detail-updater.cpp"

using namespace std;


int main()
{
	uptonow();
	Date mil,shams;
	ifstream in;
	int date;
	int month;
	int year;
	in.open("calender",ios::in);
	char c,d;
	string time;
	int nowday=1;
	int pweek=0;
	for(;!in.eof();in>>c)
	{
		if(c=='|')
		{
			pweek++;
		}
	}
	pweek/=2;
	int pday=0;
	c='s';
	if(pweek<6)
	{
		in.close();
		in.open("calender",ios::in);
		for(;c!='|';in>>c)
		{
			if(c== ':' )
			{
				pday++;
			}
		}
		ofstream out;
		out.open("calender",ios::app);
		out<<endl;
		for(int i=(pweek-1)*7 + pday;i<=5*7 || nowday!=1 ;i++)
		{
			time=nextday(i);
			time = indate(date,month,year,time);
			mil.dd=date;
			mil.mm=month;
			mil.yy=year;
			shams=gregorian_to_jalali(mil);
			out<<"!"<<days(nowday)<<":";
			out<<shams.dd<<"-"<<shams.mm<<"-"<<shams.yy;
			out<<"#";
			out<<calen(nowday)<<"--"<<endl<<endl<<endl;
			if(nowday==7)
			{
				out<<"|_____________________________|"<<endl<<endl;
				nowday=0;
			}
			nowday++;
		}
		out.close();
	}
	in.close();
}
