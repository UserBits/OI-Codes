#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100005,M=100005;
struct edge{
    int node,next,val,last;
}Edge[M];
int Head[N],n,m,tot,Dis[N];
bool v[N];
struct qn{
    int key,len;
    friend bool operator < (qn x,qn y){
        return x.len>y.len;
    }
};
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Edge[tot].last=x;
    Head[x]=tot;
}
void Dij(int s){
    for(int i=1;i<=n;i++){
        Dis[i]=1e9;
        v[i]=0;
    }
    Dis[s]=0;
    priority_queue<qn> q;
    q.push((qn){s,0});
    qn r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(v[r.key])
            continue;
        v[r.key]=1;
        for(int k=Head[r.key];k;k=Edge[k].next){
            if(Dis[r.key]+Edge[k].val<Dis[Edge[k].node]){
                Dis[Edge[k].node]=Dis[r.key]+Edge[k].val;
                q.push((qn){Edge[k].node,Dis[Edge[k].node]});
            }
        }
    }
}
int tmp[M],cnt[M],from[M],to[M];
int main(){
    scanf("%d%d",&n,&m);
    int u,v,l;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&u,&v,&l,&tmp[i]);
        from[i]=u;
        to[i]=v;
        Add(v,u,l);
    }
    Dij(n);
    for(int i=1;i<=m;i++){
        if(Dis[Edge[i].node]-Dis[Edge[i].last]==Edge[i].val)
            cnt[i]=0;
        else
            cnt[i]=1;
    }
    memset(Head,0,sizeof(Head));
    tot=0;
    for(int i=1;i<=m;i++)
        Add(to[i],from[i],tmp[i]);
    Dij(n);
    for(int i=1;i<=m;i++){
        if(Dis[Edge[i].node]-Dis[Edge[i].last]!=Edge[i].val)
            cnt[i]++;
    }
    memset(Head,0,sizeof(Head));
    tot=0;
    for(int i=1;i<=m;i++)
        Add(from[i],to[i],cnt[i]);
    Dij(1);
    printf("%d\n",Dis[n]);
    return 0;
}
