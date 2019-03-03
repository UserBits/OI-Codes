#include <cstdio>
#include <algorithm>
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

const int N=10005,M=50005;
struct edge{
    int node,next;
}Edge[M];
int Head[N],tot;
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Head[x]=tot;
}

int dfn[N],low[N],col[N],cnt[N],num,color,outd[N];
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
        col[u]=++color;
        ins[u]=0; cnt[color]=1;
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0;
            cnt[color]++; s.pop();
        }
        s.pop();
    }
}

int main(){
    int n,m,x,y;
    qr(n); qr(m);
    for(int i=1;i<=m;i++){
        qr(x); qr(y);
        Add(x,y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int k=Head[i];k;k=Edge[k].next){
            x=Edge[k].node;
            if(col[i]!=col[x])
                outd[col[i]]++;
        }
    }
    int id=0;
    for(int i=1;i<=color;i++){
        if(!outd[i]){
            if(id){
                puts("0"); return 0;
            }
            id=i;
        }
    }
    printf("%d\n",cnt[id]);
    return 0;
}

