#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1005,M=20005;
struct edge{
    int node,next,val;
}Edge[M];
int Head[N],Dis[N][N],n,m,Cnt,tot;
bool v[N][N];
struct qNode{
    int key,dep,len;
    friend bool operator < (qNode x, qNode y){
        return x.len>y.len;
    }
};
inline void Add(int x,int y,int l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].val=l;
    Head[x]=tot;
}
void Dijkstra(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=Cnt;j++)
            Dis[i][j]=1e9;
    }
    Dis[1][0]=0;
    priority_queue<qNode> q;
    q.push((qNode){1,0,0});
    qNode r;
    while(!q.empty()){
        r=q.top();
        q.pop();
        if(v[r.key][r.dep])
            continue;
        v[r.key][r.dep]=1;
        for(int k=Head[r.key];k;k=Edge[k].next){
            if(max(Dis[r.key][r.dep],Edge[k].val)<Dis[Edge[k].node][r.dep]){
                Dis[Edge[k].node][r.dep]=max(Dis[r.key][r.dep],Edge[k].val);
                q.push((qNode){Edge[k].node,r.dep,Dis[Edge[k].node][r.dep]});
            }
            if(r.dep<Cnt && Dis[r.key][r.dep]<Dis[Edge[k].node][r.dep+1]){
                Dis[Edge[k].node][r.dep+1]=Dis[r.key][r.dep];
                q.push((qNode){Edge[k].node,r.dep+1,Dis[Edge[k].node][r.dep+1]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&Cnt);
    int u,v,l;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&l);
        Add(u,v,l);
        Add(v,u,l);
    }
    Dijkstra();
    if(Dis[n][Cnt]<1e9)
        printf("%d\n",Dis[n][Cnt]);
    else
        puts("-1");
    return 0;
}