#include<cstdio>
long long f[10000005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
				f[i]+=f[i-j];
		}
		f[i]%=100003;
	}
	printf("%lld\n",f[n]);
	return 0;
}

