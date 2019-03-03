#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const ll m=123456789;
ll ksm(ll x,ll y){
    ll r=1;
    while(y){
        if(y&1)
            r=r*x%m;
        y>>=1;
        x=x*x%m;
    }
    return r;
}
int main(){
    ll k;
    scanf("%lld",&k);
    printf("%lld\n",ksm(2,k-1));
    return 0;
}