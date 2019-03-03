#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstdlib>
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

const int N=100001,M=500001;
struct edge{
    int node,next;
}Edge[M];
int Head[N],tot,Ind[N];
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Head[x]=tot;
}

int dfn[N],low[N],col[N],num,color;
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
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0; s.pop();
        }
        s.pop();
    }
}

int main(){
    int n,m,x,y;
    qr(n); qr(m);
    while(m--){
        qr(x); qr(y);
        if(x!=y)
            Add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=Head[i];j;j=Edge[j].next){
            if(col[i]!=col[Edge[j].node])
                Ind[col[Edge[j].node]]++;
        }
    }
    int ans=0;
    for(int i=1;i<=color;i++)
        ans+=(!Ind[i]);
    printf("%d\n",ans);
    return 0;
}