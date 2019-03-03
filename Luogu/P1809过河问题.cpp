#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE=100002;
int t[SIZE];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    sort(t+1,t+n+1);
    while(n>3)
    {
        if(t[2]*2<t[1]+t[n-1])
            ans+=(t[2]*2+t[n]+t[1]);
        else
            ans+=(t[1]*2+t[n-1]+t[n]);
        n-=2;
    }
    if(n==3)
        ans=ans+t[1]+t[2]+t[3];
    if(n==2)
        ans=ans+t[2];
    printf("%d\n",ans);
    return 0;
}

