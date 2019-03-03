#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll exgcd(ll a,ll b,ll &x, ll &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return d;
}
int main(){
    ll n,m,x,y,l,p,q,r;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    ll a=x-y,b=n-m;
    if(b<0){
        a=-a;
        b=-b;
    }
    r=exgcd(b,l,p,q);
    if(a%r!=0)
        puts("Impossible");
    else{
        ll t=l/r;
        printf("%lld\n",(p*a/r%t+t)%t);
    }
    //system("pause");
    return 0;
}