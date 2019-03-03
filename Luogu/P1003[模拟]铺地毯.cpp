#include <cstdio>
int a[10005],b[10005],c[10005],d[10005],n,x,y,ans;
void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		c[i]+=a[i];
		d[i]+=b[i];
	}
	scanf("%d%d",&x,&y);
}
void work()
{
	int i;
	ans=-1;
	for(i=1;i<=n;i++)
	{
		if(x>=a[i] && x<=c[i] && y>=b[i] && y<=d[i])
			ans=i;
	}
	printf("%d\n",ans);
}
int main()
{
	init();
	work();
	return 0;
}
