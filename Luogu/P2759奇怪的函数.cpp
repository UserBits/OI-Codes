#include <cstdio>
#include <cmath>
typedef long long ll;
inline ll cnt(ll x){
    return (ll)(x*log10(1.0*x))+1;
}
int main(){
    ll ans,l=1,r=1e17,mid,n;
    scanf("%lld",&n);
    while(l<=r){
        mid=(l+r)>>1;
        if(cnt(mid)>=n){
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
