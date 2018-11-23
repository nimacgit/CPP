#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,s,p;
    cin>>n>>s>>p;
    int m=n*(n-1)/2,ms=m-s,mp=m-p;
    vector <int> g;
    g.push_back(0);
    for(int i=1;i<=ms;i++)
        if(ms%i==0)
            if(i+ms%i<=n)
            g.push_back(i);
    g.push_back(n);
    for(int j=0;j<g.size();j++)
    {
        int sum=g[j];
            if(sum*(sum-1)/2==mp)
            {
                cout<<n-g[j]<<endl;
                return 0;
            }
    }
    cout<<"Liar"<<endl;
    return 0;
}
