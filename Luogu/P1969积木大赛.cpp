#include<iostream>
using namespace std;
int main()
{
    int i,n,num=0,s0=0,s1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s1;
        if(s1>s0)
            num+=s1-s0;
        s0=s1;
    }
    cout<<num<<endl;
    return 0;
}
