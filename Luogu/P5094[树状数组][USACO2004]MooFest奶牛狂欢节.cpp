#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N=20005;
typedef long long ll;
struct node{
    int snd,pos;
}a[N];
ll x[N],y[N];
bool cmp(node x,node y){
    return x.snd<y.snd;
}
int n;
inline int lowbit(int x){
    return x&(-x);
}
void upd1(int u,int v){
    while(u<=N){
        x[u]+=v;
        u+=lowbit(u);
    }
}
void upd2(int u,int v){
    while(u<=N){
        y[u]+=v;
        u+=lowbit(u);
    }
}
ll ask1(int u){
    ll ans=0;
    while(u){
        ans+=x[u];
        u-=lowbit(u);
    }
    return ans;
}
ll ask2(int u){
    ll ans=0;
    while(u){
        ans+=y[u];
        u-=lowbit(u);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].snd,&a[i].pos);
    sort(a+1,a+1+n,cmp);
    ll ans=0,p=0,S,X;
    for(int i=1;i<=n;i++){
        X=ask1(a[i].pos);
        S=ask2(a[i].pos);
        ans+=(X*a[i].pos-S+p-S-(i-1-X)*a[i].pos)*a[i].snd;
        p+=a[i].pos;
        upd1(a[i].pos,1);
        upd2(a[i].pos,a[i].pos);
    }
    cout<<ans<<endl;
    return 0;
}
