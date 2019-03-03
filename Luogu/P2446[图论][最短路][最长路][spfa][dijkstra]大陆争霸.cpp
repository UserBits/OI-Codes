#include <cstdio>
#include <cstdlib>
#include <algorithm>
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
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=3001,M=200001;
struct Edge{
    int node,next,val;
}edge[M];
int heade[N],n,m,tote;
struct Graph{
    int node,next;
}graph[M];
int headg[N],totg;

struct qnode{
    int key,len;
    friend bool operator < (qnode x,qnode y){
        return x.len<y.len;
    }
};
int dis[N],into[N],ind[N],arrive[N];
bool vis[N];
priority_queue<qnode> q;

void dijkstra(int s){
    for(int i=1;i<=n;i++)
        dis[i]=arrive[i]=1e9;
    dis[s]=into[s]=arrive[s]=0;
    ind[s]=0;
    q.push((qnode){s,0});
    int u,v;
    while(!q.empty()){
        u=q.top().key;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(int k=heade[u];k;k=edge[k].next){
            v=edge[k].node;
            if(dis[u]+edge[k].val<arrive[v]){
                arrive[v]=dis[u]+edge[k].val;
                if(!ind[v]){
                    dis[v]=max(into[v],arrive[v]);
                    q.push((qnode){v,-dis[v]});
                }
            }
        }
        for(int k=headg[u];k;k=graph[k].next){
            v=graph[k].node;
            into[v]=max(into[v],dis[u]);
            ind[v]--;
            if(!ind[v]){
                dis[v]=max(into[v],arrive[v]);
                q.push((qnode){v,-dis[v]});
            }
        }
    }
}

int main(){
    qr(n);
    qr(m);
    int x,y,l;
    while(m--){
        qr(x);
        qr(y);
        qr(l);
        edge[++tote].node=y;
        edge[tote].next=heade[x];
        edge[tote].val=l;
        heade[x]=tote;
    }
    for(int i=1;i<=n;i++){
        qr(x);
        while(x--){
            qr(y);
            ++ind[i];
            graph[++totg].node=i;
            graph[totg].next=headg[y];
            headg[y]=totg;
        }
    }
    dijkstra(1);
    printf("%d\n",dis[n]);
    //system("pause");
    return 0;
}