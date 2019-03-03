#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[4205][4205];
int main(){
	int n,mod;
	scanf("%d%d",&n,&mod);
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i][j-1]+dp[i-1][i-j])%mod;
	}
	printf("%d\n",2*dp[n][n]%mod);
	return 0;
}
