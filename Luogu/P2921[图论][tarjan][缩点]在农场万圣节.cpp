#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
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

const int N=100001;
struct Edge{
    int node,next,from;
}edge[N],graph[N];
int head[N],tot,nxt[N];
inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].from=x;
    edge[tot].next=head[x];
    head[x]=tot;
}

int dfn[N],low[N],cnt[N],col[N],color,num;
stack<int> s;
bool ins[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    ins[u]=1; s.push(u);
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
        cnt[color]=1;
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0;
            cnt[color]++;
            s.pop();
        }
        s.pop();
    }
}

int f[N];
int dfs(int k){
    if(f[k])
        return f[k];
    f[k]=dfs(nxt[k])+1;
    return f[k];
}
/*处理
在环内：ans=环内节点数
环外（即单节点）：ans=到环距离+环内节点数
*/
int main(){
    int n;
    qr(n);
    for(int i=1;i<=n;i++){
        int y;
        qr(y);
        add(i,y);
        nxt[i]=y;
        if(i==y)
            f[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);//printf("[%d]",i);
    }
    //puts("sb");
    tot=0;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++){
        int x=col[edge[i].from],y=col[edge[i].node];
        if(cnt[x]>1)
            f[i]=cnt[x];
        if(x!=y){
            graph[++tot].node=y;
            graph[tot].next=head[x];
            head[x]=tot;
        }
    }
    for(int i=1;i<=n;i++){
        if(!f[i])
            dfs(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",f[i]);
    }
    //system("pause");
}