#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,b;
struct node
{
	ll p,c;
	bool operator < (node comp)
	{
		return p<comp.p;
	}
}a[100005];
int main()
{
	scanf("%lld%lld",&n,&b);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",&a[i].p,&a[i].c);
	sort(a,a+n);
	ll t,ans=0;
	for(int i=0;i<n;i++)
	{
		t=b/a[i].p;
		if(t>a[i].c)
		{
			b-=a[i].c*a[i].p;
			ans+=a[i].c;
		}
		else
		{
			ans+=t;
			break;
		}
	}
	printf("%lld\n",ans);
}
