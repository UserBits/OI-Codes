#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int h,l,r,id;
}a[1005];
struct result
{
	int l,r;
}ans[1005];
bool cmp(node x,node y)
{
	if(x.h!=y.h)
		return x.h>y.h;
	return x.l<y.l;
}
int main()
{
	int n;
	bool p1,p2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		p1=p2=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i].l>a[j].l && a[i].l<a[j].r && !p1)
			{
				ans[a[i].id].l=a[j].id;
				p1=1;
			}
			if(a[i].r>a[j].l && a[i].r<a[j].r && !p2)
			{
				ans[a[i].id].r=a[j].id;
				p2=1;
			}
			if(p1 && p2)
				break;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ans[i].l,ans[i].r);
	return 0;
}
