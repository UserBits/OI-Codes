//Luogu P1606
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
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

const int LN=31,N=100001,M=100001;
typedef long long ll;
struct edge{
    int node,next;
}Edge[M];
int Head[N],Dis[N],n,tot;
inline void Add(int x,int y){
    Edge[++tot].node=y; Edge[tot].next=Head[x];
    Head[x]=tot;
}
ll Cnt[N];
bool Inq[N];
void spfa(int s){
    for(int i=1;i<=n;i++)
        Dis[i]=1e9;
    Dis[s]=0; Inq[s]=1; Cnt[s]=1;
    queue<int> q; q.push(s);
    int u,v;
    while(!q.empty()){
        u=q.front(); q.pop(); Inq[u]=0;
        for(int k=Head[u];k;k=Edge[k].next){
            v=Edge[k].node;
            if(Dis[u]+1<Dis[v]){
                Dis[v]=Dis[u]+1; Cnt[v]=Cnt[u];
                if(!Inq[v]){
                    Inq[v]=1; q.push(v);
                }
            }
            else if(Dis[v]==Dis[u]+1)
                Cnt[v]+=Cnt[u];
        }
    }
}

int mp[LN][LN],pre[LN][LN],ln,lm,st,ed;
bool v[LN][LN];
const int dx[8]={2,2,-2,-2,1,-1,1,-1},
          dy[8]={-1,1,-1,1,2,2,-2,-2};
void dfs(int src,int x,int y){
    v[x][y]=1; int tx,ty;
    for(int k=0;k<8;k++){
        tx=x+dx[k];
        ty=y+dy[k];
        if(tx>=0 && ty>=0 && tx<ln && ty<lm && !v[tx][ty]){
            if(mp[tx][ty]==1)
                dfs(src,tx,ty);
            else{
                v[tx][ty]=1; Add(src,pre[tx][ty]);
            }
        }
    }
}

void work(){
    qr(ln); qr(lm);
    n=ln*lm;
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++)
            pre[i][j]=i*lm+j+1;
    }
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            qr(mp[i][j]);
            if(mp[i][j]==3)
                st=pre[i][j];
            if(mp[i][j]==4)
                ed=pre[i][j];
        }
    }
    for(int i=0;i<ln;i++){
        for(int j=0;j<lm;j++){
            if(mp[i][j]==3 || mp[i][j]==0){
                memset(v,0,sizeof(v));
                dfs(pre[i][j],i,j);
            }
        }
    }
    spfa(st);
    if(Dis[ed]<1e9)
        qw(Dis[ed]-1),EOL,qw(Cnt[ed]);
    else
        puts("-1");
}

int main(){
    work();
    return 0;
}

