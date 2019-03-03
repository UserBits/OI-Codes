#include <cstdio>
#include <cstring>
typedef long long ll;
const ll mod=1000000007;
int n=2;
struct node{
	ll a[5][5];
	node(){
		memset(a,0,sizeof(a));
	}
}x,res;
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
inline void pow(long long y){
	y--;
	x.a[1][1]=x.a[1][2]=x.a[2][1]=1;
	res.a[1][1]=res.a[2][2]=1;
	while(y){
		if(y&1)
			res=multi(res,x);
		x=multi(x,x);
		y>>=1;
	}
	printf("%lld\n",(res.a[2][1]+res.a[2][2])%mod);
}
int main(){
	ll n;
	scanf("%lld",&n);
	pow(n);
}
