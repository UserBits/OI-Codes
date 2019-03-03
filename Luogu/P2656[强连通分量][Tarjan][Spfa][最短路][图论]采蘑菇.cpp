#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N=80005,M=200005;
struct edge{
    int from,node,next,val; double r;
}Edge[M];
int Head[N],Dis[N],n,m,tot;
inline void Add(int x,int y,int l,double r){
    Edge[++tot].from=x; Edge[tot].node=y;
    Edge[tot].next=Head[x]; Edge[tot].val=l;
    Edge[tot].r=r; Head[x]=tot;
}
struct gph{
    int node,next,val;
}graph[M];

int dfn[N],low[N],col[N],num,color,weight[N];
stack<int> s;
bool ins[N],Inq[N];
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
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0; s.pop();
        }
        s.pop();
    }
}

void spfa(int s){
    for(int i=1;i<=color;i++)
        Dis[i]=-1;
    queue<int> q; q.push(s);
    Inq[s]=1; Dis[s]=weight[s];
    while(!q.empty()){
        int u=q.front(),v; q.pop(); Inq[u]=0;
        for(int k=Head[u];k;k=graph[k].next){
            v=graph[k].node;
            if(Dis[u]+graph[k].val+weight[v]>Dis[v]){
                Dis[v]=Dis[u]+graph[k].val+weight[v];
                if(!Inq[v]){
                    q.push(v); Inq[v]=1;
                }
            }
        }
    }
}

int main(){
    int s,x,y,l; double r;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%lf",&x,&y,&l,&r);
        Add(x,y,l,r);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    memset(Head,0,sizeof(Head)); tot=0;
    for(int i=1;i<=m;i++){
        x=col[Edge[i].from]; y=col[Edge[i].node];
        if(x==y){
            l=Edge[i].val; r=Edge[i].r;
            while(l){
                weight[x]+=l;
                l=(int)(l*r);
            }
        }
        else{
            graph[++tot].node=y; graph[tot].next=Head[x];
            graph[tot].val=Edge[i].val; Head[x]=tot;
        }
    }
    scanf("%d",&s); s=col[s];
    spfa(s);
    int ans=0;
    for(int i=1;i<=color;i++)
        ans=max(ans,Dis[i]);
    printf("%d\n",ans);
    return 0;
}