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
void selection_sort(int a[],int n)
{
   int i,j,max;
   for(i=n;i>0;i--)
   {
      max=0;
      for(j=0;j<i;j++)
      {
         if(a[j]>a[max])
         {
            max=j;
         }
         swap(a[max],a[i-1]);
      }
   }
}
int main()
{
   int i,n,a[100];
   cout<<"enter n(n<=100):";
   cin>>n;
   for(i=0;i<n;i++)
   {
      cout<<"enter a["<<i+1<<"]:";
      cin>>a[i];
   }
   selection_sort(a,n);
   cout<<"The sorted list is:"<<endl;
   for(i=0;i<n;i++)
      cout<<a[i]<<endl;
   getch();
   return 0;
}
