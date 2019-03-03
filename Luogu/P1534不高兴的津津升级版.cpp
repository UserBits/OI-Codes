#include <cstdio>
using namespace std;
int main()
{
	int n,a,b,ans=0,sum=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		sum=sum+a+b-8;
		ans+=sum;
	}
	printf("%d\n",ans);
	return 0;
}

