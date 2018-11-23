#include<iostream>
#include<conio.h>
using namespace std;
void swap(int &x,int &y)
{
   int t;
   t=x;
   x=y;
   y=t;
}
int main()
{
   int i,j;
   cout<<"Enter i,j:";
   cin>>i>>j;
   cout<<"You have entered i="<<i<<" ,j="<<j<<endl;
   swap(i,j);
   cout<<"Now after swap i="<<i<<" ,j="<<j;
   getch();
   return 0;
}
