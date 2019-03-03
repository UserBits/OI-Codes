#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int N=100005;
ll a[N],b[N]; int n;
ll exgcd(ll A,ll B,ll &x,ll &y){
    if(!B){
        x=1; y=0;
        return A;
    }
    ll d=exgcd(B,A%B,x,y),t=x;
    x=y; y=t-A/B*y;
    return d;
}
ll multi(ll x,ll y,ll m){
    ll ans=0;
    while(y){
        if(y&1)
            ans=(ans+x)%m;
        y>>=1;
        x=(x+x)%m;
    }
    return ans;
}

ll excrt(){
    ll ans=a[1],m=b[1],x,y,c,d;
    for(int i=2;i<=n;i++){
        c=((a[i]-ans)%b[i]+b[i])%b[i];
        d=exgcd(m,b[i],x,y);
        x=multi(x,c/d,b[i]);
        ans+=m*x; m*=b[i]/d;
        ans=(ans+m)%m;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&b[i],&a[i]);
    printf("%lld\n",excrt());
    return 0;
}