#include <cstdio>
#include <cstring>
#include <cstdlib>
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

const int N=41,M=10001;
struct edge{
    int node,next;
}Edge[M];
int Head[N],Dis[2][N],tot,n,m;
bool Inq[N];
inline void Add(int x,int y){
    Edge[++tot].node=y; 
    Edge[tot].next=Head[x]; Head[x]=tot;
}

void SPFA(int k,int s){
    for(int i=1;i<=n;i++){
        Dis[k][i]=1e9; Inq[i]=0;
    }
    Dis[k][s]=0; Inq[s]=1;
    queue<int> q; q.push(s);
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int t=Head[u];t;t=Edge[t].next){
            v=Edge[t].node;
            if(Dis[k][u]+1<Dis[k][v]){
                Dis[k][v]=Dis[k][u]+1;
                if(!Inq[v]){
                    q.push(v); Inq[v]=1;
                }
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    int x,y,DC;
    while(m--){
        qr(x); qr(y);
        Add(x,y); Add(y,x);
    }
    qr(DC);
    while(DC--){
        qr(x); qr(y);
        SPFA(0,x); SPFA(1,y);
        for(int i=1;i<=n;i++){
            if(Dis[0][i]+Dis[1][i]==Dis[0][y])
                printf("%d ",i);
        }
        puts("");
    }
    return 0;
}