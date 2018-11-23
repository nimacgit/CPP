#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   int i,j,n,t,max,a[100];
   cout<<"enter n(n<=100):";
   cin>>n;
   for(i=0;i<n;i++)
   {
      cout<<"enter a["<<i+1<<"]:";
      cin>>a[i];
   }
   for(i=n;i>0;i--)
   {
      max=0;
      for(j=0;j<i;j++)
      {
         if(a[j]>a[max])
         {
            max=j;
         }
         t=a[max];
         a[max]=a[i-1];
         a[i-1]=t;
      }
   }
   cout<<"The sorted list is:"<<endl;
   for(i=0;i<n;i++)
      cout<<a[i]<<endl;
   getch();
   return 0;
}
