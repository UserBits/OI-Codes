#include <cstdio>
#include <algorithm>
using namespace std;
bool p[505];
struct node
{
	int t,w;
} a[505];
bool cmp(node x,node y)
{
	return x.w>y.w;
}
int main()
{
	int m,n,ans=0;
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i].t);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i].w);
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
 		int j=a[i].t;
		while(p[j]==1 && j>=1)
			j--;
		if(j<=0)
			m-=a[i].w;
		else
			p[j]=1;
	}
	if(m<0)
		m=0;
 	printf("%d\n",m);
	return 0;
}

