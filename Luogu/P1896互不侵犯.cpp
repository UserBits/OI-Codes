#include <cstdio>
using namespace std;
bool judge(int x)
{
	return ((x & (x<<1)) || (x & (x>>1)));
}
long long dp[10][85][101];
int can[101];
int many[101];
int main()
{
	int full;
	int n,K;
	scanf("%d%d",&n,&K);
	full=(1<<n)-1;
	int cnt=0;
	for(int i=0; i<=full; i++)
	{
		if(judge(i)) continue;
		can[++cnt]=i;
	}
	int x;
	int sum=0;
	for(int i=1; i<=cnt; i++)
	{
		x=can[i];
		while(x>0)
		{
			sum++;
			x=x-(x & (-x));
		}
		many[i]=sum;
		sum=0;

	}

	int last,lastmany;
	int now,nowmany;
	for(int i=1; i<=cnt; i++) dp[1][many[i]][i]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=cnt; j++)
		{
			last=can[j];
			for(int k=1; k<=cnt; k++)
			{
				now=can[k];
				if((now & last) || ((now>>1) & last) || ((now<<1) & last))  continue;
				nowmany=many[k];
				for(int l=nowmany; l<=K; l++)
					dp[i][l][k]+=dp[i-1][l-nowmany][j];
			}
		}
	}
	long long maxn=0ll;
	for(int i=1; i<=cnt; i++) maxn+=dp[n][K][i];
	printf("%lld",maxn);
	return 0;
}
