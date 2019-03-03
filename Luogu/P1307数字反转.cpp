#include<iostream>
using namespace std;
int main()
{
    int n,s=0;
    cin>>n;
    bool p=0;
    if(n<0)
    {
        n=-n;
        p=1;
    }
    while(n!=0)
    {
        s=s*10+n%10;
        n/=10;
    }
    if(p==1)
        cout<<'-'<<s<<endl;
    else
        cout<<s<<endl;
    return 0;
}
