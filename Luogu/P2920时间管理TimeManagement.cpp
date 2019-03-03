#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int cost,before;
}a[1005];
bool cmp(node x,node y)
{
	return x.before>y.before;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].cost,&a[i].before);
	sort(a+1,a+1+n,cmp);
	int ans=a[1].before;
	for(int i=1;i<=n;i++)
	{
		if(ans<=a[i].before)
			ans-=a[i].cost;
		else
			ans=a[i].before-a[i].cost;
	}
	if(ans<0)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}

