#include <cstdio>
#include <algorithm>
using namespace std;
int a[50005],f[50005];
int main()
{
	int h,n;
	scanf("%d%d",&h,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=h;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	}
	printf("%d\n",f[h]);
}
