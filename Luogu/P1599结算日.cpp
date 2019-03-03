#include <cstdio>
using namespace std;
int main()
{
	bool p=0;
	int n,tmp,sum=0,ans=0,l=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		sum+=tmp;
		ans++;
		if(sum>=0 && p)
		{
			p=0;
			ans+=(i-l)*2;
		}
		if(sum<0 && !p)
		{
			p=1;
			l=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}

