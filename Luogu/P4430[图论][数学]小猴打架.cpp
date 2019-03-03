#include <cstdio>
const int mod=9999991;
int main(){
	int n; long long ans=1;
	scanf("%d",&n);
	for(int i=1;i<n-1;i++)
		ans=ans*n%mod;
	for(int i=2;i<n;i++)
		ans=ans*i%mod;
	printf("%lld",ans);
	return 0;
}
