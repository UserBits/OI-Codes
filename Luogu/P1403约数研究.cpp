#include<iostream>
using namespace std;
int n,ans;
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        ans+=n/i;
    cout<<ans;
    return 0;
}
