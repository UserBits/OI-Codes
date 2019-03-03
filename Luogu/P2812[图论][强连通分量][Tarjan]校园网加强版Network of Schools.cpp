#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define EOL putchar('\n')
#define SPACE putchar(32)
#define lowbit(x) (x&(-x))
const int INF=2147483647,INE=-2147483647;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}
template<typename qWrite>
inline void qw(qWrite s){
    if(s>9)
        qw(s/10);
    putchar(s%10+'0');
}

const int N=10001,M=5000001;
struct edge{
    int node,next;
}Edge[M];
int Head[N],n,m,tot,ind[N],outd[N];
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
        ins[u]=0; col[u]=++color;
        while(s.top()!=u){
            col[s.top()]=color;
            ins[s.top()]=0; s.pop();
        }
        s.pop();
    }
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,x,y;
    qr(n);
    for(x=1;x<=n;++x){
        qr(y);
        while(y){
            Add(x,y); qr(y);
        }
    }
    for(x=1;x<=n;++x){
        if(!dfn[x])
            tarjan(x);
    }
    if(color==1){
        qw(1),EOL,qw(0);
        return 0;
    }
    for(x=1;x<=n;++x){
        for(int k=Head[x];k;k=Edge[k].next){
            y=Edge[k].node;
            if(col[x]!=col[y])
                ++ind[col[y]],++outd[col[x]];
        }
    }
    x=y=0;
    for(int i=1;i<=color;i++){
        if(!ind[i]) ++x;
        if(!outd[i]) ++y;
    }
    printf("%d\n%d\n",x,max(x,y));
    return 0;
}

