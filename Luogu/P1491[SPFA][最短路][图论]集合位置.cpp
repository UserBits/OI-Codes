#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

template<typename qRd>
inline void qr(qRd &s){
    char c=getchar();
    qRd f=1; s=0;
    for(;c<'0'||c>'9';c=getchar()){
        if(c=='-') f=-1;
    }
    for(;c>='0'&&c<='9';c=getchar())
        s=(s<<1)+(s<<3)+(c-'0');
    s*=f;
}

const int N=205,M=40005;
struct edge{
    int node,next;
    double cost;
}Edge[M];
int Head[N],tot,n,m,Pre[N],lx[N],ly[N];
double Dis[N];
bool Inq[N],Exc[N][N],Rec;
inline void Add(int x,int y,double l){
    tot++;
    Edge[tot].node=y;
    Edge[tot].next=Head[x];
    Edge[tot].cost=l;
    Head[x]=tot;
}

void SPFA(){
    for(int i=1;i<=n;i++){
        Inq[i]=0; Dis[i]=1e9;
    }
    queue<int> q;
    Inq[1]=1; Dis[1]=0; q.push(1);
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int k=Head[u];k;k=Edge[k].next){
            v=Edge[k].node;
            if(!Exc[u][v] && Dis[u]+Edge[k].cost<Dis[v]){
                if(Rec) Pre[v]=u;
                Dis[v]=Dis[u]+Edge[k].cost;
                if(!Inq[v]){
                    Inq[v]=1; q.push(v);
                }
            }
        }
    }
}

inline double Dist(int a1,int b1,int a2,int b2){
    int c1=a1-a2,c2=b1-b2;
    return sqrt(c1*c1*1.0+c2*c2*1.0);
}

int main(){
    qr(n); qr(m);
    for(int i=1;i<=n;i++){
        qr(lx[i]); qr(ly[i]);
    }
    int u,v;
    double l,ans=1e9;
    for(int i=1;i<=m;i++){
        qr(u); qr(v);
        l=Dist(lx[u],ly[u],lx[v],ly[v]);
        Add(u,v,l); Add(v,u,l);
    }
    Rec=1;
    SPFA();
    Rec=0;
    for(int i=n;i!=1;i=Pre[i]){
        Exc[i][Pre[i]]=Exc[Pre[i]][i]=1;
        SPFA(); ans=min(ans,Dis[n]);
        Exc[i][Pre[i]]=Exc[Pre[i]][i]=0;
    }
    printf("%.2lf\n",ans);
    return 0;
}