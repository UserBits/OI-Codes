#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N=105,M=3005;
struct Edge{
	int node,next,val;
}edge[M];
int head[N],dis[N],n,m,tot,vis[N];
bool inq[N];
queue<int> q;
inline void add(int x,int y,int l){
	edge[++tot].node=y;
	edge[tot].next=head[x];
	edge[tot].val=l;
	head[x]=tot;
}

bool spfa(int s){
	while(!q.empty())
		q.pop();
	for(int i=0;i<N;i++){
		dis[i]=1e9;
		inq[i]=0;
		vis[i]=0;
	}
	inq[s]=1;
	dis[s]=0;
	q.push(s);
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		inq[u]=0;
		++vis[u];
		if(vis[u]>=n){
			return 1;
		}
		for(int k=head[u];k;k=edge[k].next){
			v=edge[k].node;
			if(dis[u]+edge[k].val<dis[v]){
				dis[v]=dis[u]+edge[k].val;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}

int main(){
	int dc;
	scanf("%d",&dc);
	while(dc--){
		scanf("%d%d",&n,&m);
		memset(head,0,sizeof(head));
		tot=0;
		int x,y,l;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&l);
			add(x-1,y,l);
			add(y,x-1,-l);
		}
		for(int i=0;i<=n;i++)
			add(n+1,i,0);
		bool ans=spfa(n+1);
		if(ans)
			puts("false");
		else
			puts("true");
	}
	return 0;
}
