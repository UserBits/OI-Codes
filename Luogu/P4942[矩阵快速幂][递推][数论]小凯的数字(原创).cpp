#include <cstdio>
#include <cstring>
#include <cstdlib>
typedef long long ll;
const ll mod=9;
int n=3;
struct node{
	ll a[4][4];
	node(){
		memset(a,0,sizeof(a));
	}
};
inline node multi(node p,node q){
	node tp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				tp.a[i][j]=(tp.a[i][j]+p.a[i][k]*q.a[k][j])%mod;
		}
	}
	return tp;
}
inline void pow(ll l,ll r){
    ll y=r-l;
	node res,x;
    x.a[1][1]=x.a[1][2]=x.a[1][3]=x.a[2][2]=x.a[2][3]=1;
    x.a[3][3]=10;
	res.a[1][1]=res.a[2][2]=res.a[3][3]=1;
	while(y){
		if(y&1)
			res=multi(res,x);
		x=multi(x,x);
		y>>=1;
	}
	node ans;
    ans.a[1][1]=1; ans.a[1][2]=ans.a[1][3]=l;
    ans=multi(ans,res);
    printf("%lld\n",ans.a[1][3]);
}
int main(){
    int n;
    ll l,r;
    scanf("%d",&n);
    while(n--){
        scanf("%lld%lld",&l,&r);
        pow(l,r);
    }
    return 0;
}