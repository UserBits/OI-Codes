#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <cstring>

using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename Tp>
inline void qr(Tp &s){
    char c=gc(); 
    s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=200001;
struct Edge{
    int node,next,from;
}edge[N];
struct Head{
    int first,cost;
}head[N];
int n,tot,outd[N];
inline void add(int x,int y){
    edge[++tot].node=y;
    edge[tot].next=head[x].first;
    edge[tot].from=x;
    head[x].first=tot;
}

int dfn[N],low[N],col[N],mnc[N],color,num;
stack<int> s;
bool ins[N];
void tarjan(int u){
    dfn[u]=low[u]=++num;
    ins[u]=1;
    s.push(u);
    for(int k=head[u].first;k;k=edge[k].next){
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
        mnc[col[u]=++color]=head[u].cost;
        ins[u]=0;
        while(s.top()!=u){
            ins[s.top()]=0;
            col[s.top()]=color;
            mnc[color]=min(mnc[color],head[s.top()].cost);
            s.pop();
        }
        s.pop();
    }
}

void init(){
    qr(n);
    int x;
    for(int i=1;i<=n;i++)
        qr(head[i].cost);
    for(int i=1;i<=n;i++){
        qr(x);
        add(i,x);
    }
}

int work(){
    for(int i=1;i<=n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    int x,y;
    for(int i=1;i<=n;i++){
        x=col[edge[i].from],
        y=col[edge[i].node];
        if(x!=y)
            outd[x]++;
    }
    int ans=0;
    for(int i=1;i<=color;i++){
        if(!outd[i])
            ans+=mnc[i];
    }
    return ans;
}

int main(){
    init();
    printf("%d\n",work());
    //system("pause");
    return 0;
}