#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,m,i,s=0;
    bool p[1005]={0},k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(p[m]==0)
            s++;
        p[m]=1;
    }
    printf("%d\n",s);
    for(i=1;i<=1000;i++)
    {
        if(p[i])
        {
            if(k==0)
            {
                printf("%d",i);
                k=1;
            }
            else if(k==1)
                printf(" %d",i);
        }
    }
    return 0;
}
