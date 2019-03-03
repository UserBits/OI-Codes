#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000005],size=0;
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
int pop1()
{
	int ans=a[1],now=1,tmp;
	a[1]=a[size--];
	while((now<<1)<=size)
	{
		tmp=now<<1;
		if(tmp<size && a[tmp+1]>a[tmp])
			tmp++;
		if(now>size)
			break;
		swap(a[now],a[tmp]);
		now=tmp;
	}
	return ans;
}
int pop2()
{
	int ans=a[1],now=1,tmp;
	a[1]=a[size--];
	while((now<<1)<=size)
	{
		tmp=now<<1;
		if(tmp<size && a[tmp+1]<a[tmp])
			tmp++;
		if(now>size)
			break;
		swap(a[now],a[tmp]);
		now=tmp;
	}
	return ans;
}
/*
8
7 2 3 4 9 8 1 10
*/
int main()
{
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i=1;i<=n;i++)
		scanf("%d",&tmp),push2(tmp);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	for(int i=1;i<=n;i++)
		printf("%d ",pop2());
}
