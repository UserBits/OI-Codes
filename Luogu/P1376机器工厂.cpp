// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
inline void in(long long &s)
{
	char c=getchar();
	long long num=0,tmp=1;
	for(; c<'0' || c>'9'; c=getchar())
	{
		if(c=='-')
			tmp=-1;
	}
	for(; c>='0' && c<='9'; c=getchar())
		num=(num<<1)+(num<<3)+(c-'0');
	s=num*tmp;
}
int main()
{
	long long ans,a,b,tmp,n,s;
	in(n); in(s); in(a); in(b);
	ans=a*b;
	tmp=a;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		if(tmp+s<a)
			tmp+=s;
		else
			tmp=a;
		ans+=tmp*b;
	}
	printf("%lld\n",ans);
	return 0;
}

