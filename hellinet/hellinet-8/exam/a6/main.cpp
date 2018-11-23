#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cin>> a;
    vector<int> mi;
    vector <int>ma;
    for(int i=0; i<a; i++)
    {
        mi.push_back(0);
        ma.push_back(0);
    }
    mi[0]=1;
    ma[0]=1;
    for(int m=0,n=a-1; m!=n;)
    {
        if(mi[m]!=9)
        {
            if(ma[n]!=9)
            {
                mi[m]++;
                ma[n]++;
            }
            else
                n--;
        }
        else
            m++;
    }

    for(int j=0; j<ma.size(); j++)
        cout<<ma[j];
    cout<<endl;
    for(int j=0; j<mi.size(); j++)
        cout<<mi[j];

    return 0;
}
