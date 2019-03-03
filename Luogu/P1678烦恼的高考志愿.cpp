#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+1+m);
	sort(b+1,b+1+n);
	int tmp=1,sum=0,p;
	for(int i=1;i<=n;i++)
	{
		p=abs(b[i]-a[tmp]);
		while(abs(b[i]-a[tmp+1])<=p)
		{
			tmp++;
			p=abs(b[i]-a[tmp]);
		}
		sum+=p;
	}
	printf("%d\n",sum);
}
