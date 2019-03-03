#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n,m;
    cin>>n;
    cin>>m;
    int i,x=1,y=1;
    for(i=0;i<n.size();i++)
    {
        x*=int(n[i]-65+1);
    }
    for(i=0;i<m.size();i++)
    {
        y*=int(m[i]-65+1);
    }
    x%=47;
    y%=47;
    if(x==y)
        cout<<"GO"<<endl;
    else
        cout<<"STAY"<<endl;
    return 0;
}
