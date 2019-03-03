#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
	int n,p;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p,&a[i]);
	sort(a+1,a+1+n);
	int len=n/2,ans=0;
	for(int i=1;i<=len;i++)
		ans+=a[n-i+1]-a[i];
	printf("%d\n",ans);
	return 0;
}

