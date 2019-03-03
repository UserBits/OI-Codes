#include <cstdio>
#include <cstring>
typedef long long ll;
const ll mod=1000000007;
struct node{
	/*
	ll a[5][5];
	node(){
		memset(a,0,sizeof(a));
	}*/
	ll a,b,c,d;
}x,res;
inline node multi(node p,node q){
	node tp;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				tp.a[i][j]=(tp.a[i][j]+p.a[i][k]*q.a[k][j])%mod;
		}
	}*/
	tp.a=(p.a*q.a+p.b*q.c)%mod;
    tp.b=(p.a*q.b+p.b*q.d)%mod;
    tp.c=(p.c*q.a+p.d*q.c)%mod;
    tp.d=(p.c*q.b+p.d*q.d)%mod;
	return tp;
}
inline void pow(long long y){
	y--;
	x=(node){1,1,1,0};
	res=(node){1,0,0,1};
	while(y){
		if(y&1)
			res=multi(res,x);
		x=multi(x,x);
		y>>=1;
	}
	printf("%lld\n",(res.c+res.d)%mod);
}
int main(){
	ll n;
	scanf("%lld",&n);
	pow(n);
}
