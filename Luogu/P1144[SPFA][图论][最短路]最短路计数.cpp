#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

char ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template<typename qd>
inline void qr(qd &s){
    char c=gc(); s=0;
    for(;c<'0'||c>'9';c=gc());
    for(;c>='0'&&c<='9';c=gc())
        s=(s<<1)+(s<<3)+(c-'0');
}

const int N=1000001;
struct Ed{
    int nd,nx;
}ed[N<<2];
int hd[N],ds[N],n,m,tot,cn[N],i,u,v;
bool iq[N];
inline void add(int x,int y){
    ed[++tot].nd=y;
    ed[tot].nx=hd[x]; hd[x]=tot;
}

void spfa(int s){
    for(i=1;i<=n;++i)
        ds[i]=1e9;
    ds[s]=0; iq[s]=1; cn[s]=1;
    queue<int> q; q.push(s);
    while(!q.empty()){
        u=q.front(); q.pop(); iq[u]=0;
        for(i=hd[u];i;i=ed[i].nx){
            v=ed[i].nd;
            if(ds[v]==ds[u]+1)
                cn[v]=(cn[v]+cn[u])%100003;
            if(ds[u]+1<ds[v]){
                ds[v]=ds[u]+1;
                cn[v]=cn[u];
                if(!iq[v]){
                    iq[v]=1; q.push(v);
                }
            }
        }
    }
}

int main(){
    qr(n); qr(m);
    while(m--){
        qr(u); qr(v);
        add(u,v); add(v,u);
    }
    spfa(1);
    for(i=1;i<=n;++i)
        printf("%d\n",cn[i]);
    return 0;
}