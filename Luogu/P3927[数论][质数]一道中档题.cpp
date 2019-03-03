#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll p[1000],a[1000];
int main(){
    ll n,k,cnt=0,ans=1e18;
    scanf("%lld%lld",&n,&k);
    for(ll i=2;i*i<=k;i++){
        if(k%i==0){
            p[++cnt]=i;
            while(k%i==0){
                a[cnt]++;
                k/=i;
            }
        }
    }
    if(k>1){
        cnt++;
        p[cnt]=k; a[cnt]=1;
    }
    for(int i=1;i<=cnt;i++){
        ll t=0,f=n;
        while(f)
            t+=f/=p[i];
        t/=a[i];
        if(t<ans)
            ans=t;
    }
    printf("%lld\n",ans);
    return 0;
}