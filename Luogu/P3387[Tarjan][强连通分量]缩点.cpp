#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename Tp>
inline void qr(Tp &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=10001,M=100001;
struct edge{
    int node,next,from;
}Edge[M],graph[M];
int Head[N],tot,val[N];
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Edge[tot].from=x; Head[x]=tot;
}

int dfn[N],low[N],col[N],num,color,sum[N],ind[N],ans,dp[N];
stack<int> s;
bool ins[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    ins[u]=1; s.push(u);
    for(int k=Head[u];k;k=Edge[k].next){
        int v=Edge[k].node;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else{
            if(ins[v])
                low[u]=min(low[u],low[v]);
        }
    }
    if(dfn[u]==low[u]){
        col[u]=++color; ins[u]=0;
        sum[color]=val[u];
        while(s.top()!=u){
            sum[color]+=val[s.top()];
            col[s.top()]=color;
            ins[s.top()]=0; s.pop();
        }
        s.pop();
    }
}

void TopSort(){
    queue<int> q;
    for(int i=1;i<=color;i++){
        if(!ind[i]){
            q.push(i);
            dp[i]=sum[i];
        }
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int k=Head[u];k;k=graph[k].next){
            int v=graph[k].node;
            ind[v]--;
            dp[v]=max(dp[v],dp[u]+sum[v]);
            if(!ind[v])
                q.push(v);
        }
    }
    for(int i=1;i<=color;i++)
        ans=max(ans,dp[i]);
}

int main(){
    int n,m,x,y;
    qr(n); qr(m);
    for(int i=1;i<=n;i++)
        qr(val[i]);
    for(int i=1;i<=m;i++){
        qr(x); qr(y);
        Add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    memset(Head,0,sizeof(Head)); tot=0;
    for(int i=1;i<=m;i++){
        x=col[Edge[i].from]; y=col[Edge[i].node];
        if(x!=y){
            graph[++tot].node=y;
            graph[tot].next=Head[x];
            Head[x]=tot; ind[y]++;
        }
    }
    TopSort();
    printf("%d\n",ans);
    return 0;
}
