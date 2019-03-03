#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll ab(ll x){
    return x>=0?x:-x;
}
ll a[100005];
int main(){
    int n,m,p1,p2=1<<30;
    ll s1,s2;
    scanf("%d",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    scanf("%d%d%lld%lld",&m,&p1,&s1,&s2);
    a[p1]+=s1;
    a[m]=0;
    ll cnt1=0,cnt2=0,t1,t2,ans=1ll<<62;
    for(ll i=1;i<m;i++)
        cnt1+=a[i]*(m-i);
    for(ll i=m+1;i<=n;i++)
        cnt2+=a[i]*(i-m);
    for(ll i=1;i<=n;i++){
        if(i<m){
            t1=cnt1+s2*(m-i);
            t2=cnt2;
        }
        else if(i>m){
            t1=cnt1;
            t2=cnt2+s2*(i-m);
        }
        else{
            t1=cnt1;
            t2=cnt2;
        }
        if(ab(t1-t2)<ans){
            ans=ab(t1-t2);
            p2=i;
        }
    }
    printf("%d\n",p2);
    return 0;
}