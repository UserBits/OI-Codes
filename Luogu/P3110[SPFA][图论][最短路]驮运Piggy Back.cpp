#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
inline void qr(int &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c^48);
}
inline int mn(int x,int y){
    return x<y?x:y;
}

const int N=40001,K=3;
struct edge{
    int node,next;
}Edge[N<<1];
int n,m,tot,Dis[K][N],Head[N],v0,v1,v2,i,u,v,ans=2e9;
bool Inq[N];
inline void Add(int x,int y){
    Edge[++tot].node=y;
    Edge[tot].next=Head[x];
    Head[x]=tot;
}

void SPFA(int k,int s){
    for(i=1;i<=n;++i){
        Dis[k][i]=1e9; Inq[i]=0;
    }
    Dis[k][s]=0; Inq[s]=1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int t=Head[u];t;t=Edge[t].next){
            v=Edge[t].node;
            if(Dis[k][u]+1<Dis[k][v]){
                Dis[k][v]=Dis[k][u]+1;
                if(!Inq[v]){
                    q.push(v); Inq[v]=1;
                }
            }
        }
    }
}

int main(){
    qr(v0); qr(v1); qr(v2); qr(n); qr(m);
    while(m--){
        qr(u); qr(v);
        Add(u,v); Add(v,u);
    }
    SPFA(0,1); SPFA(1,2); SPFA(2,n);
    for(i=1;i<=n;++i)
        ans=mn(ans,Dis[0][i]*v0+Dis[1][i]*v1+Dis[2][i]*v2);
    printf("%d\n",ans);
    return 0;
}