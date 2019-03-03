#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
using namespace std;

const int N=20001,M=200001;
struct Edge{
    int node,next; 
}edge[M];
int head[N],n,m,tot;

inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

int dfn[N],low[N],num;
bool cut[N];
void tarjan(int u,int root){
    dfn[u]=low[u]=++num;
    int v,cnt=0;
    for(int k=head[u];k;k=edge[k].next){
        v=edge[k].node;
        if(!dfn[v]){
            tarjan(v,root);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<=low[v] && u!=root)
                cut[u]=1;
            if(u==root)
                cnt++;
        }
        low[u]=min(low[u],dfn[v]);
    }
    if(u==root && cnt>1)
        cut[u]=1;
}

int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cut[i])
            ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(cut[i])
            printf("%d ",i);
    }
    return 0;
}