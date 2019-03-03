#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
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

const int N=10001,M=100001,K=11;
struct edge{
	int node,next,cost;
}Edge[M];
int Head[N],Dis[N][K],n,m,k,tot;
bool vis[N][K];
struct qNode{
	int key,dep,len;
	friend bool operator < (qNode x, qNode y){
		return x.len>y.len;
	}
};

inline void Add(int x,int y,int l){
	x++; y++; tot++;
	Edge[tot].node=y;
	Edge[tot].next=Head[x];
	Edge[tot].cost=l;
	Head[x]=tot;
}

void Dijkstra(int s){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)
			Dis[i][j]=1e9;
	}
	priority_queue<qNode> q;
	Dis[s][0]=0;
	q.push((qNode){s,0,0});
	qNode r;
	int u,v,ud;
	while(!q.empty()){
		r=q.top(); q.pop(); u=r.key; ud=r.dep;
		if(vis[u][ud])
			continue;
		vis[u][ud]=1;
		for(int t=Head[u];t;t=Edge[t].next){
			v=Edge[t].node;
			if(Dis[u][ud]+Edge[t].cost<Dis[v][ud]){
				Dis[v][ud]=Dis[u][ud]+Edge[t].cost;
				q.push((qNode){v,ud,Dis[v][ud]});
			}
			if(ud<k && Dis[u][ud]<Dis[v][ud+1]){
				Dis[v][ud+1]=Dis[u][ud];
				q.push((qNode){v,ud+1,Dis[v][ud+1]});
			}
		}
	}
}

int main(){
	qr(n); qr(m); qr(k);
	int s,t,x,y,l;
	qr(s); s++; qr(t); t++;
	while(m--){
		qr(x); qr(y); qr(l);
		Add(x,y,l); Add(y,x,l);
	}
	Dijkstra(s);
	int ans=2e9;
	for(int i=0;i<=k;i++)
		ans=min(ans,Dis[t][i]);
	printf("%d\n",ans);
	return 0;
}
