#include <cstdio>
using namespace std;
int n,k,h,tmp,d;
int main()
{
	scanf("%d%d%d",&n,&k,&h);
	long long ans1=1,ans2=1,t=k;
	if(k>n)
	{
		putchar('0');
		return 0;
	}
	for(int i=1;i<=h;i++)
	{
		scanf("%d",&tmp);
		for(int j=1;j<=tmp;j++)
			ans1*=j;
	}
	d=n-k+1;
	for(int i=n;i>=d;i--)
		ans2*=i*i;
	printf("%lld\n",ans2/ans1);
	return 0;
}

