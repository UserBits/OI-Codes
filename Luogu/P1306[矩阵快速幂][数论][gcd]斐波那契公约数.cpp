#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;
const ll mod=100000000;
struct node{
	ll a,b,c,d;
}x,res;
inline node multi(node p,node q){
	node tp;
	tp.a=(p.a*q.a+p.b*q.c)%mod;
    tp.b=(p.a*q.b+p.b*q.d)%mod;
    tp.c=(p.c*q.a+p.d*q.c)%mod;
    tp.d=(p.c*q.b+p.d*q.d)%mod;
    /*
        矩阵p       矩阵q
        [a b]      [a b]
        [c d]      [c d]
        用矩阵p的第一行乘矩阵q的第一列，
        p的第一行乘q的第二列，
        p的第二行乘q的第一列，
        p的第二行乘q的第二列。
    */
	return tp;
}
inline long long pow(int y){ //矩阵快速幂
	y--;
	x=(node){1,1,1,0};
	res=(node){1,0,0,1};
	while(y){
		if(y&1)
			res=multi(res,x);
		x=multi(x,x);
		y>>=1;
	}
	return (res.c+res.d)%mod;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    n=gcd(n,m);
    if(n<=2)
        puts("1");
    else
        printf("%lld\n",pow(n));
    //system("pause");
    return 0;
}