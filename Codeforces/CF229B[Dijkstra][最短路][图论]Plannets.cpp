#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>

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
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=200001,M=400001;
struct Edge{
    int node,next,val;
}edge[M];
int head[N],n,m,tot;
long long dis[N];
set<int> p[N];
bool vis[N];

struct qnode{
    int key;
    long long len;
    friend bool operator < (qnode x, qnode y){
        return x.len>y.len;
    }
};
priority_queue<qnode> q;

inline void add_edge(int x,int y,int l){
    edge[++tot].node=y;
    edge[tot].next=head[x];
    edge[tot].val=l;
    head[x]=tot;
}

void dijkstra(int s){
    for(int i=1;i<=n;i++)
        dis[i]=1e18;
    dis[s]=0;
    q.push((qnode){s,0});
    qnode u;
    int v;
    while(!q.empty()){
        u=q.top();
        q.pop();
        if(vis[u.key])
            continue;
        vis[u.key]=1;
        while(p[u.key].count(u.len))
            u.len++;
        for(int k=head[u.key];k;k=edge[k].next){
            v=edge[k].node;
            if(u.len+edge[k].val<dis[v]){
                dis[v]=u.len+edge[k].val;
                q.push((qnode){v,dis[v]});
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    int x,y,l;
    while(m--){
        qr(x), qr(y), qr(l);
        add_edge(x,y,l);
        add_edge(y,x,l);
    }
    for(int i=1;i<=n;i++){
        qr(x);
        while(x--){
            qr(y);
            p[i].insert(y);
        }
    }
    dijkstra(1);
    printf("%lld\n",(dis[n]==1e18)?-1:dis[n]);
    return 0;
}