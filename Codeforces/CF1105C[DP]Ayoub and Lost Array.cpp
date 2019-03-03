#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=200001,mod=1e9+7;
typedef long long ll;
int pre[N];
ll f[N][3];
int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	pre[0]=r/3-(l-1)/3;
	pre[1]=(r+2)/3-(l+1)/3;
	pre[2]=(r+1)/3-l/3;
	for(int i=0;i<3;i++)
		f[1][i]=pre[i];
	for(int i=2;i<=n;i++){
		f[i][0]=(f[i-1][0]*pre[0]+f[i-1][1]*pre[2]+f[i-1][2]*pre[1])%mod;
		f[i][1]=(f[i-1][0]*pre[1]+f[i-1][1]*pre[0]+f[i-1][2]*pre[2])%mod;
		f[i][2]=(f[i-1][0]*pre[2]+f[i-1][2]*pre[0]+f[i-1][1]*pre[1])%mod;
	}
	printf("%lld\n",f[n][0]);
	return 0;
}
