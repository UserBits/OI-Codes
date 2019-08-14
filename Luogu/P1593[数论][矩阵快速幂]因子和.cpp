#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll x[10005],y[10005];
const int mod=9901,N=2;
struct node{
	ll a[4][4];
	node(){
		memset(a,0,sizeof(a));
	}
};
inline node multi(node p,node q){
	node tp;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++)
				tp.a[i][j]=(tp.a[i][j]+p.a[i][k]*q.a[k][j]%mod)%mod;
		}
	}
	return tp;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int len=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            x[++len]=i;
            y[len]=0;
            while(n%i==0){
            	y[len]++;
                n/=i;
            }
        }
    }
    if(n>1){
        x[++len]=n;
        y[len]=1;
    }
    for(int i=1;i<=len;i++)
        y[i]*=m;
    ll ans=1;
    for(int i=1;i<=len;i++){
        node f,res;
        ll t=y[i]+1;
        res.a[1][1]=res.a[2][2]=1;
        f.a[1][1]=x[i];
        f.a[1][2]=f.a[2][2]=1;
        while(t){
            if(t&1)
                res=multi(res,f);
            t>>=1;
            f=multi(f,f);
        }
        ans=ans*res.a[1][2]%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
