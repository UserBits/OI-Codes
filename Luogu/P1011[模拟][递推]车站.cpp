#include<iostream>
using namespace std;
const int N=2005;
int main()
{
    int a,n,m,x,la[N],lb[N];
    cin>>a>>n>>m>>x;
    la[1]=1;
    la[2]=0;
    la[3]=1;
    lb[1]=0;
    lb[2]=1;
    lb[3]=1;
    for(int i=4;i<=n-1;i++)
    {
        la[i]=la[i-1]+la[i-2];
        lb[i]=lb[i-1]+lb[i-2];
    }
    int sa=1,sb=1;
    for(int i=3;i<=n-1;i++)
        sa+=la[i]-la[i-1];
    for(int i=3;i<=n-1;i++)
        sb+=lb[i]-lb[i-1];
    sb--;
    int b=(m-sa*a)/sb;
    sa=sb=0;
    for(int i=1;i<=x;i++)
        sa+=la[i];
    for(int i=1;i<=x;i++)
        sb+=lb[i];
    for(int i=3;i<=x;i++)
        sa-=la[i-1];
    for(int i=3;i<=x;i++)
        sb-=lb[i-1];
    if(x>=2)
        sb--;
    cout<<sa*a+sb*b;
    return 0;
}

