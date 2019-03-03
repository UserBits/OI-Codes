#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int N=5001,M=100001;
struct Edge{
	int node,next;
}edge[M];
int head[N],tot,low[N],dfn[N],col[N],sum[N],num,color;
inline void add(int x,int y){
	edge[++tot].node=y; edge[tot].next=head[x]; head[x]=tot;
}

bool ins[N]; stack<int> s;
void tarjan(int u){
	low[u]=dfn[u]=++num;
	ins[u]=1; s.push(u);
	for(int k=head[u];k;k=edge[k].next){
		int v=edge[k].node;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else{
			if(ins[v])
				low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		col[u]=++color; sum[color]=1;
		while(s.top()!=u){
			col[s.top()]=color; sum[color]++;
			ins[s.top()]=0; s.pop();
		}
		ins[u]=0; s.pop();
	}
}

int main(){
	int n,m,x,y,t;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&x,&y,&t);
		if(t==1) add(x,y);
		else add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=max(ans,sum[i]);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(sum[col[i]]==ans){
			for(int j=i;j<=n;j++){
				if(col[j]==col[i])
					printf("%d ",j);
			}
			return 0;
		}
	}
	return 0;
}
