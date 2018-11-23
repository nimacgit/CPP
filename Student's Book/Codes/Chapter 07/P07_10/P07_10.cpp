#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int i,j,k;
   char ch,str[256];
   string s, t[100];
   cout<<"Enter your string:";
   getline(cin,s);
   cout<<"Enter your separator character:";
   cin>>ch;
   j=0;
   k=0;
   for(i=0;i<s.length();i++)
       if(s[i]==ch)
       {
          str[k]=0;
          t[j]=string(str);
          j++;
          k=0;
       }
       else
       {
          str[k]=s[i];
          k++;
       }
   if(k!=0)
   {
      str[k]=0;
      t[j]=string(str);
      j++;
   }
   for(i=0;i<j;i++)
      cout<<t[i]<<endl;
   getch();
   return 0;
}
