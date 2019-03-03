#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int s[1001],f[1001][1001],g[1001][1001],dp[1001][1001],a[1001];
inline void qr(int &s){
	s=0;
	int t=1;
	register char c=getchar();
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')
			t=-1;
	}
	for(;c>='0'&&c<='9';c=getchar())
		s=(s<<1)+(s<<3)+c-'0';
	s*=t;
}
int main(){
	int t,n,i,j,l;
	qr(t);
	while(t--){
		qr(n);
		for(i=1;i<=n;++i){
			qr(a[i]);
			dp[i][i]=f[i][i]=g[i][i]=a[i];
			s[i]=s[i-1]+a[i];
		}
		for(l=1;l<=n;++l){
			for(i=1;i<=n;++i){
				j=i+l-1;
				if(j>n)
					break;
				dp[i][j]=s[j]-s[i-1]-min(min(f[i+1][j],g[i][j-1]),0);
				f[i][j]=min(dp[i][j],f[i+1][j]);
				g[i][j]=min(dp[i][j],g[i][j-1]);
			}
		}
		printf("%d\n",dp[1][n]);
	}
    return 0;
}