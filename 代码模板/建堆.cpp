#include <cstdio>
#include <algorithm>
using namespace std;
int a[10000005],size=0;
void push1(int d)
{
	a[++size]=d;
	int now=size,tmp;
	while(now>1)
	{
		tmp=now>>1;
		if(a[tmp]<=a[now])
			swap(a[tmp],a[now]);
		else
			break;
		now>>=1;
	}
}
void push2(int d)
{
	a[++size]=d;
	int now=size,tmp;
	while(now>1)
	{
		tmp=now>>1;
		if(a[tmp]>=a[now])
			swap(a[tmp],a[now]);
		else
			break;
		now>>=1;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i=1;i<=n;i++)
		scanf("%d",&tmp),push2(tmp);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
