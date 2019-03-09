#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=500001;
struct Edge{
    int node,next;
}edge[N<<1];
int head[N],dep[N],fa[N][20],n,q,rt,tot,x,y;
inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void dfs(int u,int pre){//预处理深度
    for(int k=head[u];k;k=edge[k].next){
        int v=edge[k].node;
        if(v==pre)
            continue;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v,u);
    }
}

int main(){
    scanf("%d%d%d",&n,&q,&rt);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    fa[rt][0]=rt; //标记根
    dfs(rt,rt);
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    }
    while(q--){
        scanf("%d%d",&x,&y);
        if(dep[x]>dep[y])
            swap(x,y);
        int t=dep[y]-dep[x];
        for(int i=0;(1<<i)<=t;i++){
            if((1<<i)&t)
                y=fa[y][i];
        }
        if(x!=y){
            for(int i=(int)log2(n);i>=0;i--){
                if(fa[x][i]!=fa[y][i]){
                    x=fa[x][i];
                    y=fa[y][i];
                }
            }
            x=fa[x][0];
        }
        printf("%d\n",x);
    }
    return 0;
}