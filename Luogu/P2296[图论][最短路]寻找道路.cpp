#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=10005,M=200005;
struct edge{
    int node,next;
}Edge[M];
struct qn{
    int key,val;
    friend bool operator < (qn x, qn y){
        return x.val>y.val;
    }
};
int Head[N],Dis[N],n,m,tot,s,t,f[N];
bool g[N],v[N];
void pre(){
    queue<int> q;
    q.push(t);
    g[t]=1;
    int r;
    while(!q.empty()){
        r=q.front();
        q.pop();
        for(int k=Head[r];k;k=Edge[k].next){
            if(!g[Edge[k].node]){
                g[Edge[k].node]=1;
                q.push(Edge[k].node);
            }
        }
    }
}
inline bool check(int r){
    if(!g[r])
        return 0;
    for(int k=Head[r];k;k=Edge[k].next){
        if(!g[Edge[k].node])
            return 0;
    }
    return 1;
}
void Dijkstra(){
    priority_queue<qn> q;
    q.push((qn){s,0});
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Dis[s]=0;
    qn r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(v[r.key])
            continue;
        v[r.key]=1;
        for(int k=Head[r.key];k;k=Edge[k].next){
            if(Dis[r.key]+1<Dis[Edge[k].node] && check(Edge[k].node)){
                Dis[Edge[k].node]=Dis[r.key]+1;
                q.push((qn){Edge[k].node,Dis[Edge[k].node]});
            }
        }
    }
}
int x[M],y[M];
inline void Add(int x,int y){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Head[x]=tot;
}
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
        Add(y[i],x[i]);
    }
    scanf("%d%d",&s,&t);
    pre();
    memset(Head,0,sizeof(Head));
    tot=0;
    for(int i=1;i<=m;i++)
        Add(x[i],y[i]);
    Dijkstra();
    if(Dis[t]<1e9)
        printf("%d\n",Dis[t]);
    else
        puts("-1");
    return 0;
}
