#include <cstdio>

const int N=2005;
int a[N],dp[N][N],sum[N];

inline int mx(int a,int b){
	return a>b?a:b;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>0;i--)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k=j*2-1;
			dp[i][j]=dp[i][j-1];
			if(k<=i)
				dp[i][j]=mx(dp[i][j],sum[i]-dp[i-k][k]);
			k++;
			if(k<=i)
				dp[i][j]=mx(dp[i][j],sum[i]-dp[i-k][k]);
		}
	}
	printf("%d\n",dp[n][1]);
	return 0;
}
