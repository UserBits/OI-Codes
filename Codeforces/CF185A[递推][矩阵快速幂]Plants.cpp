#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
struct node{
	ll a,b,c,d;
}x,res;
inline node multi(node p,node q){
	node tp;
	tp.a=(p.a*q.a+p.b*q.c)%mod;
    tp.b=(p.a*q.b+p.b*q.d)%mod;
    tp.c=(p.c*q.a+p.d*q.c)%mod;
    tp.d=(p.c*q.b+p.d*q.d)%mod;
	return tp;
}
inline void pow(long long y){
	x=(node){3,1,1,3};
	res=(node){1,0,0,1};
	while(y){
		if(y&1)
			res=multi(res,x);
		x=multi(x,x);
		y>>=1;
	}
	cout<<res.a<<endl;
}
int main(){
	ll n;
	cin>>n;
	pow(n);
    return 0;
}