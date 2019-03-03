#include <cstdio>
using namespace std;
const int N=1005;
int a[N],tmp[N],n,m,ans,x;
void move(int x,int y)
{
    if(a[x]==y)
		return;
    for(int i=x-1;i>=1;i--)
		move(i,6-a[x]-y);
    printf("move %d from %c to %c\n",x,a[x]+64,y+64);
    a[x]=y;
		ans++;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
	{
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			a[x]=i;
		}
    }
    for(int i=1;i<=3;i++)
	{
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			tmp[x]=i;
		}
    }
    for(int i=n;i>=1;i--)
		move(i,tmp[i]);
    printf("%d\n",ans);
    return 0;
}

