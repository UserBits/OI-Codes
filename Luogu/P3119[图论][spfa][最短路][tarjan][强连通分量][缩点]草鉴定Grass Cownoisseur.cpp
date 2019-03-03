#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
const int N=100001;
struct Edge{
    int from,node,next;
}edge[N];
struct Graph{
    int node,next;
}graph[N];
int head[N],dis[N][2],n,m,tot;
inline void add(int x,int y){
    edge[++tot].from=x; edge[tot].node=y;
    edge[tot].next=head[x]; head[x]=tot;
}

int dfn[N],low[N],col[N],sum[N],color,num;
bool ins[N],inq[N];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++num;
    s.push(u); ins[u]=1;
    for(int k=head[u],v;k;k=edge[k].next){
        v=edge[k].node;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else{
            if(ins[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        col[u]=++color; sum[color]=1;
        while(s.top()!=u){
            col[s.top()]=color; ++sum[color];
            ins[s.top()]=0; s.pop();
        }
        ins[u]=0; s.pop();
    }
}

void spfa(int src,int k){
    memset(inq,0,sizeof(inq));
    queue<int> q; q.push(src);
    inq[src]=1; dis[src][k]=sum[src];
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop(); inq[u]=0;
        for(int t=head[u];t;t=graph[t].next){
            v=graph[t].node;
            if(dis[u][k]+sum[v]>dis[v][k]){
                dis[v][k]=dis[u][k]+sum[v];
                if(!inq[v])
                    inq[v]=1,q.push(v);
            }
        }
    }
}

int solve(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    memset(head,0,sizeof(head)); tot=0;
    for(int i=1;i<=m;i++){
        x=col[edge[i].from]; y=col[edge[i].node];
        if(col[x]!=col[y]){
            graph[++tot].next=head[x];
            graph[tot].node=y; head[x]=tot;
        }
    }
    int src=col[1];
    spfa(src,0);
    memset(head,0,sizeof(head)); tot=0;
    for(int i=1;i<=m;i++){
        x=col[edge[i].from]; y=col[edge[i].node];
        if(x!=y){
            graph[++tot].next=head[y];
            graph[tot].node=x; head[y]=tot;
        }
    }
    spfa(src,1);
    int ans=-1;
    for(int i=1;i<=m;i++){
        x=col[edge[i].node]; y=col[edge[i].from];
        if(x==y)
            continue;
        if(dis[x][0] && dis[y][1])
            ans=max(ans,dis[x][0]+dis[y][1]-sum[src]);
    }
    return ans;
}

int main(){
    printf("%d\n",solve());
    return 0;
}