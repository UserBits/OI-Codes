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
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c^48);
}

typedef long long ll;
const int N=1005,M=105;
struct edge{
    int len,cnt;
}Edge[N][N];
int City[N],t[M],n,m,i,j,u,v,a,b;
ll Dis[N];
bool Inq[N];

void SPFA(int s){
    for(i=1;i<=n;++i){
        Dis[i]=1e18; City[i]=1e9;
    }
    queue<int> q;
    q.push(s); Inq[s]=1;
    Dis[s]=0; City[s]=0;
    ll x; int y;
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(v=1;v<=n;++v){
            if(Edge[u][v].len<1e9){
                x=Dis[u]+Edge[u][v].len;
                y=City[u]+Edge[u][v].cnt;
                if(x<Dis[v]){
                    Dis[v]=x;
                    City[v]=y;
                    if(!Inq[v]){
                        q.push(v); Inq[v]=1;
                    }
                }
                else if(x==Dis[v] && y<City[v])
                    City[v]=y;
            }
        }
    }
}

int main(){
    qr(a); qr(b); qr(m);
    int x,y;
    for(i=1;i<N;++i){
        for(j=1;j<N;++j)
            Edge[i][j].len=Edge[i][j].cnt=1e9;
    }
    while(m--){
        qr(x); qr(y);
        for(i=1;i<=y;++i){
            qr(t[i]);
            n=t[i]>n?t[i]:n;
        }
        for(i=1;i<y;++i){
            for(j=i+1;j<=y;++j){
                if(x<Edge[t[i]][t[j]].len){
                    Edge[t[i]][t[j]].len=x;
                    Edge[t[i]][t[j]].cnt=j-i;
                }
                else if(x==Edge[t[i]][t[j]].len && j-i<Edge[t[i]][t[j]].cnt)
                    Edge[t[i]][t[j]].cnt=j-i;
            }
        }
    }
    SPFA(a);
    if(Dis[b]<1e18)
        printf("%lld %d\n",Dis[b],City[b]);
    else
        puts("-1 -1");
    return 0;
}