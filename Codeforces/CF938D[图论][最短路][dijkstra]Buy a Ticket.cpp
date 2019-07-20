#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

char ss[1<<18],*A=ss,*B=ss;
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

const int N=200005,M=600005;
struct Edge{
    int node,next;
    long long val;
}edge[M];
struct Head{
    int first;
    long long cost;
}head[N];
int n,m,tot;
long long dis[N];
bool vis[N];

struct qnode{
    int key;
    long long len;
    friend bool operator < (qnode x,qnode y){
        return x.len>y.len;
    }
};
priority_queue<qnode> q;

inline void add_edge(int x,int y,long long l){
    edge[++tot].node=y;
    edge[tot].next=head[x].first;
    edge[tot].val=l;
    head[x].first=tot;
}

void dijkstra(int s){
    for(int i=1;i<N;i++)
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
        for(int k=head[u.key].first;k;k=edge[k].next){
            v=edge[k].node;
            if(dis[u.key]+edge[k].val<dis[v]){
                dis[v]=dis[u.key]+edge[k].val;
                q.push((qnode){v,dis[v]});
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    int x,y;
    long long l;
    for(int i=1;i<=m;i++){
        qr(x),qr(y),qr(l);
        add_edge(x,y,l*2);
        add_edge(y,x,l*2);
    }
    for(int i=1;i<=n;i++){
        qr(head[i].cost);
        add_edge(n+1,i,head[i].cost);
    }
    dijkstra(n+1);
    for(int i=1;i<=n;i++)
        printf("%lld ",dis[i]);
    return 0;
}