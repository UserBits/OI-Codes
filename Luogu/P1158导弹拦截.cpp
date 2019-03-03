#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long l;
	int i;
}p1[100005];
bool cmp(node a,node b)
{
	return a.l>b.l;
}
long long p2[100000];
int main()
{
	int x1,y1,x2,y2,n,x,y,i;
	long long xl,yl,minn,ans,maxn;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		p1[i].i=i;
		xl=x-x1;
		yl=y-y1;
		p1[i].l=xl*xl+yl*yl;
		xl=x-x2;
		yl=y-y2;
		p2[i]=xl*xl+yl*yl;
	}
	sort(p1,p1+n,cmp);
	minn=p1[0].l;
	maxn=0;
	for (i=1; i<n; i++)
	{
		if (p2[p1[i-1].i]>maxn)
			maxn=p2[p1[i-1].i];
		ans=p1[i].l+maxn;
		if (minn>ans)
			minn=ans;
	}
	printf("%lld",minn);
	return 0;
}
