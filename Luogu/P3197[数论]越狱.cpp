#include <cstdio>
#include <cstdlib>
typedef long long ll;
const int mod=100003;
ll q_pow(ll x,ll y){
    ll r=1;
    while(y){
        if(y&1)
            r=r*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return r;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&m,&n);
    printf("%lld\n",((q_pow(m,n)-m*q_pow(m-1,n-1))%mod+mod)%mod);
    //system("pause");
    return 0;
}