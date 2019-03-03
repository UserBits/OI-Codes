// luogu-judger-enable-o2
#include<cstdio>
using namespace std;
int n,m,water[10005],sum[105],maxn;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&water[i]);
    for(int i=1;i<=n;i++)
    {
        maxn=1;
        for(int j=2;j<=m;j++)
        {
         	if(sum[maxn]>sum[j])
			 	maxn=j;
		}
        sum[maxn]+=water[i];
    }
    maxn=1;
    for(int i=1;i<=m;i++)
		maxn=sum[i]>maxn?sum[i]:maxn;
    printf("%d",maxn);
    return 0;
}
