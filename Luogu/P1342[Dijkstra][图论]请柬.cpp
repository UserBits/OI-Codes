#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qRead>
inline void qr(qRead &s){
    char c=gc();
    s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c^48);
}

const int N=1000005;
struct edge{
    int node,next,cost;
}Edge[N];
struct tmp{
    int x,y,l;
}a[N];
int Head[N],n,m,tot,i,Dis[N];
bool v[N];
struct qNode{
    int key,len;
    friend bool operator < (qNode x, qNode y){
        return x.len>y.len;
    }
};

inline void Add(int u,int v,int l){
    tot++;
    Edge[tot].node=v;
    Edge[tot].next=Head[u];
    Edge[tot].cost=l;
    Head[u]=tot;
}

inline void Dijkstra(){
    priority_queue<qNode> q;
    q.push((qNode){1,0}); Dis[1]=0;
    register int x,y,k;
    while(!q.empty()){
        x=q.top().key; q.pop();
        if(v[x])
            continue;
        v[x]=1;
        for(k=Head[x];k;k=Edge[k].next){
            y=Edge[k].node;
            if(!v[y] && Dis[x]+Edge[k].cost<Dis[y]){
                Dis[y]=Dis[x]+Edge[k].cost;
                q.push((qNode){y,Dis[y]});
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    register long long ans=0;
    for(i=1;i<=m;++i){
        qr(a[i].x); qr(a[i].y); qr(a[i].l);
        Add(a[i].x,a[i].y,a[i].l);
    }
    for(i=1;i<=n;++i)
        Dis[i]=1e9;
    Dijkstra();
    for(i=1;i<=n;++i)
        ans+=Dis[i];
    tot=0;
    for(i=1;i<=n;++i){
        v[i]=0; Dis[i]=1e9; Head[i]=0;
    }
    for(i=1;i<=m;++i)
        Add(a[i].y,a[i].x,a[i].l);
    Dijkstra();
    for(i=1;i<=n;++i)
        ans+=Dis[i];
    printf("%lld\n",ans);
    return 0;
}