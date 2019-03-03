#include<cstdio>
#include<algorithm>
using namespace std;
int n,st,t[1005],w[1005],dp[1005][1005][2];
int sum(int a,int b)
{
	int res=0;
	if(a>st-1)a=st-1;
	if(b<st-1)b=st-1;
	for(int i=0; i<n; i++)
	{
		if(i>=a && i<=b)continue;
		res+=w[i];
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&st);
	for(int i=0; i<n; i++)
		scanf("%d%d",&t[i],&w[i]);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	dp[st-1][st-1][0]=0;
	dp[st-1][st-1][1]=0;
	for(int j=st; j<n; j++)
	{
		dp[st-1][j][1]=dp[st-1][j-1][1]+sum(st-1,j-1)*(t[j]-t[j-1]);
		dp[st-1][j][0]=dp[st-1][j][1]+sum(st-1,j)*(t[j]-t[st-1]);
	}
	for(int i=st-2; i>=0; i--)
	{
		dp[i][st-1][0]=dp[i+1][st-1][0]+sum(i+1,st-1)*(t[i+1]-t[i]);
		dp[i][st-1][1]=dp[i][st-1][0]+sum(i,st-1)*(t[st-1]-t[i]);
	}
	for(int i=st-2; i>=0; i--)
	{
		for(int j=st; j<n; j++)
		{
			dp[i][j][0]=
			    min(dp[i+1][j][1]+sum(i+1,j)*(t[j]-t[i]),
			        dp[i+1][j][0]+sum(i+1,j)*(t[i+1]-t[i]));
			dp[i][j][1]=
			    min(dp[i][j-1][1]+sum(i,j-1)*(t[j]-t[j-1]),
			        dp[i][j-1][0]+sum(i,j-1)*(t[j]-t[i]));
		}
	}
	int res=min(dp[0][n-1][0],dp[0][n-1][1]);
	printf("%d",res);
	return 0;
}

