#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline void qr(int &s){
    s=0;
    char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+c-'0';
}

const int N=101;
struct node{
    int a[N][N];
}x;
int k,n,m,s,e,f[1001];

node multi(node x,node y){
    node r;
    memset(r.a,0x3f,sizeof(r.a));
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                r.a[i][j]=min(r.a[i][j],x.a[i][k]+y.a[k][j]);
        }
    }
    return r;
}

void init(){
    memset(x.a,0x3f,sizeof(x.a));
    qr(k); qr(m); qr(s); qr(e);
    int u,v,l;
    while(m--){
        qr(l); qr(u); qr(v);
        if(!f[u])
            f[u]=++n;
        if(!f[v])
            f[v]=++n;
        x.a[f[u]][f[v]]=min(x.a[f[u]][f[v]],l);
        x.a[f[v]][f[u]]=x.a[f[u]][f[v]];
    }
}

void work(){
    node ans;
    memset(ans.a,0x3f,sizeof(ans.a));
    for(int i=1;i<=n;i++)
        ans.a[i][i]=0;
    while(k){
        if(k&1)
            ans=multi(ans,x);
        k>>=1;
        x=multi(x,x);
    }
    printf("%d\n",ans.a[f[s]][f[e]]);
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    init();
    work();
    return 0;
}
