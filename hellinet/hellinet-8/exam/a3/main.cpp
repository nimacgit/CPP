#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    vector<char> s;
    s.push_back('d');
    s.push_back('g');
    s.push_back('l');
    for(int i=0;i<n-1;i++)
    {
        s.push_back(s[0]);
        s.push_back(s[0]);
        s.push_back(s[0]);
        s.erase(s.begin()+0,s.begin()+1);
    }
    if(s[0]=='l')
        cout<<"luleE"<<endl;
    if(s[0]=='d')
        cout<<"deraz"<<endl;
    if(s[0]=='g')
        cout<<"gerd"<<endl;
    return 0;
}
