#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[1000005],f[1000005],ans[1000005];
inline void read(ll &s)
{
	char c=getchar();
	ll num=0,f=1;
	for(; c<'0' || c>'9'; c=getchar())
	{
		if(c=='-')
			f=-1;
	}
	for(; c>='0' && c<='9'; c=getchar())
		num=(num<<1)+(num<<3)+(c-'0');
	s=num*f;
}
int main()
{
	ll n,p,sum=0;
	bool flag=0;
	read(n);
	read(p);
	for(int i=0;i<n;i++)
		read(a[i]);
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		f[i]=sum;
		if(sum<0)
			sum=0;
	}
	for(int i=1;i<n;i++)
		f[i]=max(f[i],f[i-1]);
	ans[0]=f[0];
	ans[1]=ans[0]+f[0];
	for(int i=2;i<n;i++)
	{
		ans[i]=ans[i-1];
		if(f[i-1]>0)
			ans[i]+=f[i-1];
		if(ans[i]>ans[0])
			flag=1;
		if(flag)
			ans[i]%=p;
	}
	if(flag)
		printf("%lld\n",ans[n-1]%p);
	else
		printf("%lld\n",ans[0]%p);
}
