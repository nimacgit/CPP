#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;
//gets the number of day from now and return that days detail for exp: tomorrow = 2 , day after tommorow=3 , ...
string nextday(int day)
{
   time_t rawtime;
   struct tm * timeinfo;
   char buffer[80];
   time (&rawtime);
   rawtime+=day*86400;
   timeinfo = localtime(&rawtime);
   strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
   string str(buffer);
   return str;
}
//name of days of a week
string days(int a)
{
   string days[8];
   days[1]="شنبه";
   days[2]="یکشنبه";
   days[3]="دوشنبه";
   days[4]="سه شنبه";
   days[5]="چهارشنبه";
   days[6]="پنجشنبه";
   days[7]="جمعه";
   return days[a];
}
//my daily calender
string calen(int a)
{
   string calen[8];
   calen[1]="‫شیمی - هندسه - آزمون-زبان";
   calen[2]="آزشیمی/مهارت - دینی - آمار و ترکیبیات ";
   calen[3]="عربی - فیزیک - ریاضی - ادبیات";
   calen[4]="ریاضی - ورزش - فیزیک - زبان،فارسی";
   calen[5]="فیزیک - هندسه - ریاضی - شیمی-زبان ";
   calen[6]="کامپیوتر - پژوهشی-کلاس،المپیاد";
   return calen[a];
}

//shows the number of today(now)
int findtoday()
{
   time_t result = time(NULL);
   string timer = asctime(localtime(&result));
   string now;
   for(int i=0;timer[i]!=' ';i++)
      now+=timer[i];
   if(now == "Thu")
      return 6;
   else
      if(now == "Fri")
         return 7;
      else
         if(now == "Sat")
            return 1;
         else
            if(now == "Sun")
               return 2;
            else
               if(now == "Mon")
                  return 3;
               else
                  if(now == "Tue")
                     return 4;
                  else
                     if(now == "Wed")
                        return 5;

}

//shows current date and time
string timer()
{
   time_t rawtime;
   struct tm * timeinfo;
   char buffer[80];
   time (&rawtime);
   timeinfo = localtime(&rawtime);
   strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
   string str(buffer);
   return str;
}

//time_t result = time(NULL);
//cout << asctime(localtime(&result));
//inter makes a string into int for exp. input: (string)12 out: (int)12
int inter(string a)
{
   int temp=0;
   for(int i=0;i<a.length();i++)
   {
      temp=temp*10+a[i]-48;
   }
   return temp;
}  
//like indate but with reverse day and year position
string rev(string s)
{
   string tem;
   string d;
   string m;
   string y;
   int a=0;
   s+=' ';
   for(int i=0;i<s.length();i++)
   {
      if(s[i]=='-' || s[i]==' ')
      {
         if(a==0)
         {
            a++;
            d=tem;
            tem="";
         }
         else
            if(a==1)
            {
               a++;
               m=tem;
               tem="";
            }
            else
               if(a==2)
               {
                  a++;
                  y=tem;
                  tem="";
               }
         }
         else
            tem+=s[i];
      
   }
   return y+"-"+m+"-"+d;
}

//make string date like 13-7-2013 into integer of them
string indate(int & date , int & month , int & year , string & time)
{
   string temp;
   int intemp=0;
   for(int i=0;i<time.length()  ;i++)
   {
      if( time[i]=='-' || time[i]==' ')
      {
         if(intemp==0)
         {
            date = inter(temp);
            intemp++;
            temp=time[i+1];
            i+=1;
         }
         else
         if (intemp==1)
         {
               month = inter(temp);
               intemp++;
               temp=time[i+1];
               i+=1;
         }
         else
         if (intemp==2)
         {
               year = inter(temp);
               intemp++;
               temp=time[i+1];
               i+=1;
         }
      }
      else
         temp+=time[i];
   }
   return temp;
}


//making miladi to shamsi date
struct Date
{
   int yy,mm,dd;
};
#define div(x,y) ((x)/(y))
Date gregorian_to_jalali(const Date &g)
{
   int i,g_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   j_days_in_month[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};




   int gy = g.yy-1600, gm = g.mm-1, gd = g.dd-1, g_day_no = 365*gy+div(gy+3,4)-div(gy+99,100)+div(gy+399,400);

   for (i=0; i < gm; ++i)
      g_day_no += g_days_in_month[i];
   if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
      /* leap and after Feb */
      g_day_no++;
   g_day_no += gd;

   int j_day_no = g_day_no-79, j_np = div(j_day_no, 12053);/* 12053 = 365*33 + 32/4 */ 
   j_day_no = j_day_no % 12053;
   int jy = 979+33*j_np+4*div(j_day_no,1461); /* 1461 = 365*4 + 4/4 */
   j_day_no %= 1461;
   if (j_day_no >= 366) 
   {
      jy += div(j_day_no-1, 365);
      j_day_no = (j_day_no-1)%365;
   }

   for (i = 0; i < 11 && j_day_no >= j_days_in_month[i]; ++i)
      j_day_no -= j_days_in_month[i];
   int jm = i+1, jd = j_day_no+1;
   Date Result;
   Result.yy=jy;
   Result.mm=jm;
   Result.dd=jd;
   return Result;
}
//test main function
/*int main()
{
   Date a,b;
   a.dd=18;
   a.mm=9;
   a.yy=2014;
   b=gregorian_to_jalali(a);
   cout<<b.yy<<'-';
   cout<<b.mm<<'-';
   cout<<b.dd<<endl;
   return 0;
}*/



//show de diffrent of today from a date
int deffrent(int & day , int & month , int & year)
{
   Date mil,shams;
   int todday, todmonth,todyear;
   string s;
   for(int i =0;i>-50;i--)
   {
      s=nextday(i);
      indate(todday,todmonth,todyear,s);
      mil.dd=todday;
      mil.mm=todmonth;
      mil.yy=todyear;
      shams=gregorian_to_jalali(mil);
      todyear=shams.yy;
      todmonth=shams.mm;
      todday=shams.dd;
      if(todday==day && todmonth==month && year==todyear)
      {
         return -1*i;
         cout<<i<<endl;
      }
   }

}
