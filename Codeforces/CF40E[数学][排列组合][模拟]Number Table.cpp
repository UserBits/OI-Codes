#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=1001;
int mp[N][N];
template<typename qRead>
inline void qr(qRead &s){
    char c=getchar();
    s=0;
    int f=1;
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-')
            f=-1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
    s*=f;
}
ll ksm(ll x,ll y,ll m){
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
    ll n,m;
    int x,y,v,p,k;
    qr(n); qr(m); qr(k);
    for(int i=1;i<=k;i++){
        qr(x); qr(y); qr(v);
        if(n<m)
            swap(x,y);
        mp[x][y]=v;
    }
    qr(p);
    if(n<m)
        swap(n,m);
    if((n-m)&1){
        puts("0");
        return 0;
    }
    ll cnt=(n-1)*(m-1)-k;
    for(int i=1;i<=n;i++){
        int t=0;
        v=1;
        for(int j=1;j<=m;j++){
            if(mp[i][j]!=0){
                t++; v*=mp[i][j];
            }
        }
        if(t==m){
            if(v==1){
                puts("0");
                return 0;
            }
            cnt++;
        }
    }
    cout<<ksm(2,cnt,p)<<endl;
    return 0;
}