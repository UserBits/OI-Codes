#include<iostream>
using namespace std;
int x[5001],y[5001],a,b,n,s,t=0;
bool used[5001];
int main()
{
    cin>>n>>s;
    cin>>a>>b;
    a=a+b;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        cin>>y[i];
        used[i]=0;
    }
    for(int i=1;i<=n;i++)
    if(x[i]>a) used[i]=1;
        int i=0;
        while(s>=0)
        {
           int j=10000,k=1;
           i=1;
           while(used[i]&&i<=n) i++;
           while(i<=n)
               {
                   if(j>y[i]&&!used[i])
               {
                   j=y[i];
                   k=i;
               }
                   i++;
               }
            used[k]=1;
            s-=j;
            t++;
        }
    cout<<t-1;
    return 0;
}
