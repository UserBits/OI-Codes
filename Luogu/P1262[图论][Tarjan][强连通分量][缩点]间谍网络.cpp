#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstdlib>
using namespace std;

const int N=3001,M=8001;
struct Edge{
    int node,next;
}edge[M];
int head[N],cost[N],n,r,q,ind[N],tot;
inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

int dfn[N],low[N],col[N],color,num,sum[N];
bool ins[N];
stack<int> s;
void tarjan(int u){
    dfn[u]=low[u]=++num;
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
    if(low[u]==dfn[u]){
        ins[u]=0;
        col[u]=++color;
        sum[color]=cost[u];
        while(s.top()!=u){
            ins[s.top()]=0;
            col[s.top()]=color;
            sum[color]=min(sum[color],cost[s.top()]);
            s.pop();
        }
        s.pop();
    }
}

int main(){
    scanf("%d%d",&n,&q);
    int x,y;
    for(int i=1;i<=n;i++)
        cost[i]=1e9;
    while(q--){
        scanf("%d%d",&x,&y);
        cost[x]=y;
    }
    scanf("%d",&r);
    for(int i=1;i<=r;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i] && cost[i]<1e9)
            tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            printf("NO\n%d\n",i);
            return 0;
        }
    }
    for(x=1;x<=n;x++){
        for(int q=head[x];q;q=edge[q].next){
            y=edge[q].node;
            if(col[x]!=col[y])
                ind[col[y]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!ind[i])
            ans+=sum[i];
    }
    printf("YES\n%d\n",ans);
    return 0;
}
