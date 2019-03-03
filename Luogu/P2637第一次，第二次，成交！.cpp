#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+m);
	int sum=0,maxn=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]*(m-i+1)>maxn)
		{
			maxn=a[i]*(m-i+1);
			sum=a[i];
		}
	}
	printf("%d %d\n",sum,maxn);
	return 0;
}

