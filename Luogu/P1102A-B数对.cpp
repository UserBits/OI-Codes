#include <cstdio>
#include <map>
using namespace std;
int a[200005];
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	map<int,int>p;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",a+i);
		p[a[i]]++;
	}
	long long ans=0;
	for(int i=1; i<=n; i++)
		ans+=p[a[i]+c];
	printf("%lld\n",ans);
}
