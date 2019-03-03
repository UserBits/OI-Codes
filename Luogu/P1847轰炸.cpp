#include <cstdio>
using namespace std;
long long n,m,x1[10005],y1[10005],x2[10005],y2[10005],x[10005],y[10005],d[2005],p[2005];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i]);
	for(int i=1; i<=m; i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(x[j]>=x1[i] && x[j]<=x2[i] && y[j]>=y1[i] && y[j]<=y2[i])
				d[j]++,p[j]=i;
		}
	}
	for(int i=1; i<=m; i++)
	{
		if(d[i]==0)
		{
			printf("NO\n");
			continue;
		}
		printf("YES %d %d\n",d[i],p[i]);
	}
	return 0;
}

