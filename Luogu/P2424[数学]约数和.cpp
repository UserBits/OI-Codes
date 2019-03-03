#include <cstdio>
typedef long long ll;
ll sum(ll n){
    if(n<2)
        return n;
    ll s=0,r;
    for(ll l=1;l<=n;l=r+1){
        r=n/(n/l);
        s+=(n/l)*(l+r)*(r-l+1)/2;
    }
    return s;
}
int main(){
    ll x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",sum(y)-sum(x-1));
    return 0;
}