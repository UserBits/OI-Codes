#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

template<typename qRd>
inline void qr(qRd &s){
    char c=getchar();
    qRd f=1; s=0;
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-') f=-1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
    s*=f;
}

const int N=1005,M=1000005;
struct edge{
    int node,next,cost;
}Edge[M];
int Head[N],tot,n,m,Dis[N],Pre[N];
bool Rec,Inq[N],Exc[N][N];
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}

void SPFA(){
    for(int i=1;i<=n;i++){
        Dis[i]=1e9; Inq[i]=0;
    }
    queue<int> q;
    q.push(1);
    Inq[1]=1;
    Dis[1]=0;
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int k=Head[u];k;k=Edge[k].next){
            v=Edge[k].node;
            if(!Exc[u][v] && Dis[u]+Edge[k].cost<Dis[v]){
                if(Rec) Pre[v]=u;
                Dis[v]=Dis[u]+Edge[k].cost;
                if(!Inq[v]){
                    Inq[v]=1; q.push(v);
                }
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    int x,y,l,ans=0;
    for(int i=1;i<=m;i++){
        qr(x); qr(y); qr(l);
        Add(x,y,l); Add(y,x,l);
    }
    Rec=1;
    SPFA();
    Rec=0;
    for(int i=n;i!=1;i=Pre[i]){
        Exc[i][Pre[i]]=Exc[Pre[i]][i]=1;
        SPFA();
        Exc[i][Pre[i]]=Exc[Pre[i]][i]=0;
        ans=max(ans,Dis[n]);
    }
    printf("%d\n",ans);
    return 0;
}