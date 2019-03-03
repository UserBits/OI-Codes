#include <cstdio>
typedef long long ll;
const ll prime[11]={0,2,3,5,7,11,13,17,19,23,29};
ll n,ap_ans,f_ap;
void dfs(ll dep,ll sum,ll fx_now,ll maxn){
	if(dep>10)
		return;
	if(fx_now>f_ap && sum<=n){
		f_ap=fx_now;
		ap_ans=sum;
	}
	if(fx_now==f_ap && sum<ap_ans)
		ap_ans=sum;
	for(ll i=1;i<=maxn;i++){
		sum*=prime[dep];
		if(sum>n)
			break;
		dfs(dep+1,sum,fx_now*(i+1),i);
	}
}
int main(){
	while(~scanf("%lld",&n)){
		f_ap=ap_ans=-1e9;
		dfs(1,1,1,20);
		printf("%lld\n",ap_ans);
	}
	return 0;
}
