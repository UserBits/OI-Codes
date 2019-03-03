#include <cstdio>

typedef long long ll;

const int mod=998244353;

ll ksm(ll x,ll y){
	ll r=1;
	while(y){
		if(y&1)
			r=r*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return r;
}

int main(){
	int t;
	ll n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",ksm(2,(n-1)*(m-1)));
	}
	return 0;
}
