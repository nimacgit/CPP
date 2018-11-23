#include <iostream>
//#include <time.h>
#include <ctime>
#include <fstream>
#include "convertor.cpp"
#include <string>
#include <vector>

using namespace std;


int main()
{
	string time = timer();
	Date mil,shams;
	int date;
	int month;
	int year;
	time = indate(date,month,year,time);
	mil.dd=date;
	mil.mm=month;
	mil.yy=year;
	shams=gregorian_to_jalali(mil);
	ofstream out;
	out.open("calender.txt", ios::out);
	cout<<date<<"  "<<month<<"  "<<year<<"  "<<time<<endl;
	cout<<shams.dd<<"  "<<shams.mm<<"  "<<shams.yy<<endl;
	//out<<"تاریخ : "<<endl;
	int nowday;
	nowday=findtoday();
	for(int i=0;i<=35 || nowday!=1 ;i++)
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
}
