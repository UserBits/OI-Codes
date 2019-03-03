// luogu-judger-enable-o2
#include <cstdio>
using namespace std;
int f[15][15]={1};
int jc(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++)
		ans*=i;
	return ans;
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=r;j++)
			f[i][j]=f[i-1][j-1]+j*f[i-1][j];
	}
	printf("%d\n",f[n][r]*jc(r));
	return 0;
}

