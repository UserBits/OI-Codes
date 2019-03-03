#include <cstdio>
#include <algorithm>
#include <queue>
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

const int N=200005,M=1000005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N],n,m,s,t,tot;
bool vis[N];
inline void Add(int x,int y,int l){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Edge[tot].val=l; Head[x]=tot;
    Edge[++tot].node=x; Edge[tot].next=Head[y];
    Edge[tot].val=l; Head[y]=tot;
}
struct qNode{
    int key,len;
    friend bool operator < (qNode x, qNode y){
        return x.len>y.len;
    }
};

struct loc{
    int x,y,id;
}Loc[N];
bool cmp1(loc p,loc q){
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
bool cmp2(loc p,loc q){
    if(p.y!=q.y) return p.y<q.y;
    return p.x<q.x;
}

void Dijkstra(){
    for(int i=1;i<N;i++)
        Dis[i]=1e9;
    priority_queue<qNode> q; Dis[s]=0;
    q.push((qNode){s,0}); int u,v;
    while(!q.empty()){
        u=q.top().key; q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int k=Head[u];k;k=Edge[k].next){
            v=Edge[k].node;
            if(Dis[u]+Edge[k].val<Dis[v]){
                Dis[v]=Dis[u]+Edge[k].val;
                q.push((qNode){v,Dis[v]});
            }
        }
    }
}

void Prework(){
    qr(n); qr(m);
    n=m+2; s=n-1; t=n;
    for(int i=1;i<=n;i++){
        qr(Loc[i].x); qr(Loc[i].y);
        Loc[i].id=i;
    }
    sort(Loc+1,Loc+1+n,cmp1);
    for(int i=1;i<n;i++){
        if(Loc[i].x==Loc[i+1].x)
            Add(Loc[i].id,Loc[i+1].id,2*(Loc[i+1].y-Loc[i].y));
    }
    sort(Loc+1,Loc+1+n,cmp2);
    for(int i=1;i<n;i++){
        if(Loc[i].y==Loc[i+1].y)
            Add(Loc[i].id+n,Loc[i+1].id+n,2*(Loc[i+1].x-Loc[i].x));
    }
    for(int i=1;i<=m;i++)
        Add(i,i+n,1);
    Add(n-1,n*2-1,0); Add(n,n<<1,0);
}

int main(){
    Prework();
    Dijkstra();
    if(Dis[t]<1e9)
        qw(Dis[t]);
    else
        puts("-1");
    return 0;
}