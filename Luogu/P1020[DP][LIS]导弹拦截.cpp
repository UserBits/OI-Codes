#include <cstdio>
#include <algorithm>
using namespace std;
int k,ans1,ans2,temp[100005],num2[100005];
struct node
{
	int integer;
}d[100005],num1[100005];
bool operator < (const node &x,const node &y)
{
	return x.integer>y.integer;
}
int main()
{
	while(~scanf("%d",&num1[++k].integer));
	k--;
	for(int i=1; i<=k; i++)
		num2[i]=num1[i].integer;
	temp[1]=num2[1];
	ans2=1;
	d[1].integer=num1[1].integer;
	ans1=1;
	for(int i=2; i<=k; i++)
	{
		int p=upper_bound(d+1,d+ans1+1,num1[i])-d;
		d[p].integer=num1[i].integer;
		ans1=max(ans1,p);
	}
	for(int i=2; i<=k; i++)
	{
		int q=lower_bound(temp+1,temp+ans2+1,num2[i])-temp;
		temp[q]=num2[i];
		ans2=max(ans2,q);
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}

