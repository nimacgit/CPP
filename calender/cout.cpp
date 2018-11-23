#include <iostream>
//#include <time.h>
#include <ctime>
#include <string>
#include <fstream>
#include "convertor.cpp"

using namespace std;

// Thu , Fri , Sat , Sun , Mon , Tue , Wed , 
int main()
{
  /* for(int i=0;i<8;i++)
   {
      time_t result = time(NULL);
      cout << asctime(localtime(&result))<<endl;
   }*/
   ifstream i;
   i.open("calender",ios::in);
   ofstream o;
   o.open("ctemp",ios::out);
   string s;
   for(char c;!i.eof();)
   {
      i>>c;
      if(c==':')
      {  
         o<<s<<endl;
         break;
      }
      else 
         s+=c;
   }
   /*time_t rawtime;
   struct tm * timeinfo;
   char buffer[80];
   time (&rawtime);
   cout<<rawtime<<endl;
   rawtime+=1*86400;
   timeinfo = localtime(&rawtime);
   cout<<localtime(&rawtime)<<endl;
   strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
   cout<<buffer<<endl;
   string str(buffer);
   */
  } 