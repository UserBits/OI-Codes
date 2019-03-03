#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

#define EOL putchar('\n')
#define SPACE putchar(32)
#define lowbit(x) (x&(-x))
const int INF=2147483647,INE=-2147483647;
template<typename qRead>
inline void qr(qRead &s){
    char c=getchar(); s=0;
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
}
template<typename qWrite>
inline void qw(qWrite s){
    if(s>9)
        qw(s/10);
    putchar(s%10+'0');
}

const int N=500001;
struct edge{
    int node,next;
}Edge[N],Graph[N];
int Head[N],Hd[N],n,m,tot,Dis[N],val[N];
bool Inq[N];
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Head[x]=tot;
}

int dfn[N],low[N],col[N],num,color,sum[N];
bool Ins[N]; stack<int> s;
void Tarjan(int u){
    low[u]=dfn[u]=++num;
    Ins[u]=1; s.push(u);
    for(int k=Head[u];k;k=Edge[k].next){
        int v=Edge[k].node;
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else{
            if(Ins[v])
                low[u]=min(low[u],low[v]);
        }
    }
    if(low[u]==dfn[u]){
        col[u]=++color; sum[color]=val[u];
        while(s.top()!=u){
            col[s.top()]=color;
            sum[color]+=val[s.top()];
            Ins[s.top()]=0; s.pop();
        }
        Ins[u]=0; s.pop();
    }
}

void Spfa(int s){
    for(int i=1;i<=color;i++)
        Dis[i]=-1;
    queue<int> q; int u,v;
    Dis[s]=sum[s]; Inq[s]=1; q.push(s);
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int k=Hd[u];k;k=Graph[k].next){
            v=Graph[k].node;
            if(Dis[u]+sum[v]>Dis[v]){
                Dis[v]=Dis[u]+sum[v];
                if(!Inq[v]){
                    Inq[v]=1; q.push(v);
                }
            }
        }
    }
}

int main(){
    qr(n); qr(m); int x,y;
    for(int i=1;i<=m;i++){
        qr(x); qr(y);
        Add(x,y);
    }
    for(int i=1;i<=n;i++)
        qr(val[i]);
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            Tarjan(i);
    }
    tot=0;
    for(int i=1;i<=n;i++){
        for(int k=Head[i],j;k;k=Edge[k].next){
            j=Edge[k].node;
            if(col[i]!=col[j]){
                Graph[++tot].node=col[j];
                Graph[tot].next=Hd[col[i]];
                Hd[col[i]]=tot;
            }
        }
    }
    qr(x); qr(y);
    x=col[x];
    Spfa(x); int ans=-1;
    while(y--){
        qr(x);
        if(Dis[col[x]]>ans)
            ans=Dis[col[x]];
    }
    qw(ans);
    return 0;
}