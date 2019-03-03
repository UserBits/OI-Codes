#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int start,end;
} a[10005];
bool cmp(node x,node y)
{
	return x.start<y.start;
}
int main()
{
	//freopen("muds.in","r",stdin);
	//freopen("muds.out","w",stdout);
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i].start,&a[i].end);
	sort(a,a+n,cmp);
	int left=-1<<30,ans=0,t;
	for(int i=0; i<n; i++)
	{
		if (left<a[i].start)
			left=a[i].start;
		t=(a[i].end-left+l-1)/l;
		ans+=t;
		left+=t*l;
	}
	printf("%d\n",ans);
	return 0;
}
