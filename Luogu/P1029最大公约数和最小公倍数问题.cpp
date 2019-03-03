#include<iostream>
using namespace std;
int m,n,ans;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main()
{
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i*i<=k;i++)
    {
        if(k%i==0 && gcd(i,k/i)==n)
            ans++;
    }
    cout<<ans*2;
    return 0;
}
