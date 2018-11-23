#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
   int i,j,n,t,a[100];
   cout<<"enter n(n<=100):";
   cin>>n;
   for(i=0;i<n;i++)
   {
      cout<<"enter a["<<i+1<<"]:";
      cin>>a[i];
   }
   for(i=n-1;i>0;i--)
      for(j=0;j<i;j++)
         if(a[j]>a[j+1])
         {
            t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
         }
   cout<<"The sorted list is:"<<endl;
   for(i=0;i<n;i++)
      cout<<a[i]<<endl;
   getch();
   return 0;
}
