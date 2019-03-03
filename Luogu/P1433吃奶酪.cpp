#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double ans=1231234424.0;
int n;
bool p[20];
struct node
{
	double x,y;
}a[20];
double dis(double x1,double x2,double y1,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int step,double nx,double ny,double len)
{
	if(len>ans)
		return;
	if(step==n)
	{
		ans=min(ans,len);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i]==0)
		{
			p[i]=1;
			dfs(step+1,a[i].x,a[i].y,len+dis(nx,a[i].x,ny,a[i].y));
			p[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	dfs(0,0.0,0.0,0.0);
	printf("%.2lf\n",ans);
	return 0;
}
