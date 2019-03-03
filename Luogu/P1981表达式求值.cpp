#include <cstdio>
using namespace std;
const int mod=10000;
int main()
{
	int ans,sum=0,n,m;
	char c=0,k;
	bool p=1;
	while(p)
	{
		scanf("%d",&ans);
		p=scanf("%c",&k)==1?1:0;
		if(c==0)
			n=ans;
		if(c=='+')
		{
			sum=(sum%mod+n%mod)%mod;
			n=ans;
		}
		if(c=='*')
			n=(n%mod*(ans%mod))%mod;
		if(!p)
			sum=(sum%mod+n%mod)%mod;
		c=k;
	}
	printf("%d\n",sum);
	return 0;
}
