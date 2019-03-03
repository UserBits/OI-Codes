#include <algorithm>
#include <cstdio>
using namespace std;
int x[10005],y[10005];
int abs(int x)
{
	return x>0?x:-x;
}
int main()
{
	int n,a,b,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&x[i],&y[i]);
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for(int i=1; i<=n; i++)
		x[i]-=i;
	sort(x+1,x+n+1);
	if(n%2==0)
	{
		a=(x[n/2]+x[n/2+1])/2;
		b=(y[n/2]+y[n/2+1])/2;
	}
	else
	{
		a=x[n/2+1];
		b=y[n/2+1];
	}
	for(int i=1; i<=n; i++)
		ans+=abs(a-x[i])+abs(b-y[i]);
	printf("%d\n",ans);
	return 0;
}
