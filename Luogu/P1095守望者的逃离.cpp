#include <cstdio>
using namespace std;
int f[300005];
int main()
{
    int m,s,t,i;
    scanf("%d%d%d",&m,&s,&t);
    f[0]=0;
    for(i=1;i<=t;i++)
    {
        if(m>9)
        {
            f[i]=f[i-1]+60;
            m-=10;
        }
        else
        {
            f[i]=f[i-1];
            m+=4;
        }
    }
    for(int i=1;i<=t;i++)
    {
        if(f[i]<f[i-1]+17)
            f[i]=f[i-1]+17;
        if(f[i]>=s)
        {
            printf("Yes\n%d\n",i);
            return 0;
        }
    }
    printf("No\n%d\n",f[t]);
    return 0;
}
