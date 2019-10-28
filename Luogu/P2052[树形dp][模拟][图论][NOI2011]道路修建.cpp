#include <cstdio>
#include <cmath>

const int N=1000005;
struct Edge{
	int node,next,val;
}edge[N<<1];
int head[N],n,tot,siz[N];
inline void add_edge(int x,int y,int l){
	edge[++tot].node=y;
	edge[tot].next=head[x];
	edge[tot].val=l;
	head[x]=tot;
}
long long ans;

void dfs(int u,int fa){
	siz[u]=1;
	for(int k=head[u],v;k;k=edge[k].next){
		v=edge[k].node;
		if(v==fa)
			continue;
		dfs(v,u);
		ans+=(long long)abs(n-2*siz[v])*edge[k].val;
		siz[u]+=siz[v];
	}
}

int main(){
	scanf("%d",&n);
	int x,y,l;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&l);
		add_edge(x,y,l);
		add_edge(y,x,l);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
