#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		b[i]=a[i+1]-a[i];
	sort(b,b+n-1);
	for(int i=0;i<k;i++)
		ans+=b[i];
	printf("%d\n",ans);
	return 0;
}
