#include<iostream>
using namespace std;
int main()
{
    int n,k,s;
    cin>>n>>k;
    s=n;
    while(n>=k)
    {
        int m=n%k;
        n/=k;
        s+=n;
        n+=m;
    }
    cout<<s<<endl;
    return 0;
}
