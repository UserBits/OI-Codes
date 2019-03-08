#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

const int N=200001,M=1000001;
struct Edge{
    int node,next,val;
}edge[M],graph[M];
int head[N],hg[N],low[N],dfn[N],col[N],num,tot,color,dis[N],n,m;
bool ins[N],inq[N];
stack<int> s;
queue<int> q;
inline void add(int x,int y,int l){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    edge[tot].val=l;
    head[x]=tot;
}

void tarjan(int u){
    low[u]=dfn[u]=++num;
    ins[u]=1;
    s.push(u);
    for(int k=head[u];k;k=edge[k].next){
        int v=edge[k].node;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else{
            if(ins[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        col[u]=++color;
        ins[u]=0;
        while(s.top()!=u){
            ins[s.top()]=0;
            col[s.top()]=color;
            s.pop();
        }
        s.pop();
    }
}

void spfa(int s){
    for(int i=1;i<=color;i++)
        dis[i]=1e9;
    dis[s]=0;
    inq[s]=1;
    q.push(s);
    int u,v;
    while(!q.empty()){
        u=q.front();
        inq[u]=0;
        q.pop();
        for(int k=hg[u];k;k=graph[k].next){
            v=graph[k].node;
            if(dis[u]+graph[k].val<dis[v]){
                dis[v]=dis[u]+graph[k].val;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int x,y,l;
    while(m--){
        scanf("%d%d%d",&x,&y,&l);
        add(x,y,l);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    tot=0;
    for(int i=1;i<=n;i++){
        for(int k=head[i];k;k=edge[k].next){
            int j=edge[k].node;
            if(col[i]!=col[j]){
                graph[++tot].node=col[j];
                graph[tot].next=hg[col[i]];
                graph[tot].val=edge[k].val;
                hg[col[i]]=tot;
            }
        }
    }
    spfa(col[1]);
    printf("%d\n",dis[col[n]]);
    //system("pause");
    return 0;
}
